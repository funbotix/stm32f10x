# define the app name
APP_NAME := funbotix

# set AUTOMATIC to 1 to automatically use all C source and object files in this directory
# set AUTOMATIC to 0 to manually create/maintain the list of C source and object files to use
AUTOMATIC := 1

# create list of C source files needed to auto-generate the list of compiler dependancy files
ifeq ($(AUTOMATIC),1)
SOURCES := $(wildcard *.c)
else
SOURCES := main.c startup.c ...add files here as necessary...
endif

# create list of object files needed by the linker
ifeq ($(AUTOMATIC),1)
OBJECTS := $(subst .c,.o,$(SOURCES))
else
OBJECTS := main.o startup.o ...add files here as necessary...
endif

###############################################################################
# edit with caution
###############################################################################

# create path to where GCC tools are located
#TOOLPATH := C:\ARMTC\GCCARM\bin
TOOLPATH := $(GCC_HOME)

# create variables that point to the required GCC tools
COMPILE := $(strip $(TOOLPATH))\arm-none-eabi-gcc
LINK    := $(strip $(TOOLPATH))\arm-none-eabi-ld
OBJCOPY := $(strip $(TOOLPATH))\arm-none-eabi-objcopy
OBJDUMP := $(strip $(TOOLPATH))\arm-none-eabi-objdump

# create variables that are used as options to the GCC tools
LINKER_SCRIPT  := stm32.ld
LINKER_FLAGS   := -T$(strip $(LINKER_SCRIPT)) -o
COMPILER_FLAGS := -c -mcpu=cortex-m3 -mthumb

###############################################################################
# do not edit below this line
###############################################################################

# create the output filenames from the app name
ELF_FILE := $(strip $(APP_NAME)).elf
BIN_FILE := $(strip $(APP_NAME)).bin
HEX_FILE := $(strip $(APP_NAME)).hex

# this is the default make target
all: $(APP_NAME)

#auto-generate a list of dependancy files include them in this makefile
include $(subst .c,.d,$(SOURCES))

# create dependancy files from C files
%.d: %.c
	@echo '*** DEPENDANCY: $@'
	$(COMPILE) -M $< > $@

# create object files from C files and dependancy files
# the dependancy files change if header files are added, deleted, or changed
# the dependancy files are not used as sources to the compiler
# but rather as signals to make that the compile operation must be performed
%.o: %.c %.d
	@echo '*** COMPILING: $<'
	$(COMPILE) $(COMPILER_FLAGS) $< -o $@

# make the ELF file by linking the object files
# make the BIN file from the ELF file
# make the HEX file from the ELF file
$(APP_NAME): $(OBJECTS) $(LINKER_SCRIPT)
	@echo '*** LINKING:'
	$(LINK) $(LINKER_FLAGS) $(ELF_FILE) $(OBJECTS)
	$(OBJCOPY) -O binary $(ELF_FILE) $(BIN_FILE) 
	$(OBJCOPY) -O ihex $(ELF_FILE) $(HEX_FILE) 
	
# make target to remove temp files (ignore errors if files don't exist)
clean:
	@echo '*** CLEANING:'
	-rm -f *.d
	-rm -f *.o
	-rm -f *.elf
	-rm -f *.bin
	-rm -f *.hex
