# Variables del microprocesador elegido
MCU=atmega328p #Arduino Uno/Nano/etc
#MCU=atmega2560  #Arduino Mega

F_CPU=16000000
ARCH=avr
# Variables de programacion (el baudrate depende del bootloader del arduino usado)
BRATE=115200
# Variable del programador usado, este puede ser un arduino como un usbasp
PROGRAMER= arduino
# Puerto serie creado por el programador (la regla udev de usbasp genera un puerto serie en /dev/usbasp )
PORT=/dev/ttyACM0

#bootloader para flashar  ATmegaBOOT_168_atmega328.hex o optiboot_atmega328.hex
BOOTLOADER= ATmegaBOOT_168_atmega328.hex


# Variables para generar el nombre del binario a partir del directorio
EJECUTABLE := $(notdir $(shell pwd))
TARGET=$(EJECUTABLE)

# Variable para conocer el sistema del Host
ifeq ($(OS),Windows_NT)
    SYSTEM = Windows
		CD := \
else
    SYSTEM = $(shell uname -s)
		CD := /
endif

# Variables de directorios
SRC_PATH := app$(CD)src
SOURCES := $(wildcard $(SRC_PATH)$(CD)*.c)
INC_PATH := -I app$(CD)inc
OUT_PATH := out
OBJ_PATH := $(OUT_PATH)$(CD)obj

# Incluir los demas Makefiles
include drivers$(CD)Makefile
include libraries$(CD)lcd$(CD)Makefile
include libraries$(CD)onewire$(CD)Makefile
include libraries$(CD)ds18b20$(CD)Makefile


CONF_PATH  = $(shell pwd)$(CD)conf
TOOLS_PATH = $(shell pwd)$(CD)tools$(CD)$(ARCH)$(CD)bin
OBJ        = out$(CD)obj
OBJS       = $(addprefix $(OBJ)$(CD), $(notdir $(SOURCES:.c=.o)))
OBJ_FILES := $(addprefix $(shell pwd)$(OBJ_PATH)$(CD),$(notdir $(OBJS)))

vpath %.c $(SRC_PATH)
vpath %.o $(OBJ_PATH)

# Variables de compilador
CC=$(TOOLS_PATH)$(CD)avr-gcc
CFLAGS=-std=c11 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} $(INC_PATH)
CFLAGOBJ= -c
OBJCOPY=$(TOOLS_PATH)$(CD)avr-objcopy

SIZE=$(TOOLS_PATH)$(CD)avr-size
SFLAGS=-C --mcu=${MCU} --format=avr

# Regla all para compatibilizar con eclipse out of the box
all: $(TARGET)

# Regla de linkeo y generacion de direcctorios de salida (si no existen)
$(TARGET): $(OUT_PATH) $(OBJS)
	@echo Creando $@... con $^
	${CC} ${CFLAGS} $(OBJS) -o out$(CD)$@.bin
	${OBJCOPY} -j .text -j .data -O ihex $(OUT_PATH)$(CD)$(TARGET).bin  $(OUT_PATH)$(CD)${TARGET}.hex
	${SIZE} ${SFLAGS} $(OUT_PATH)$(CD)$(TARGET).bin

$(OBJ)$(CD)%.o: %.c
	@echo Creando $@... con $^
	${CC} ${CFLAGS} ${CFLAGOBJ}  $< -o $@

# Regla de limpieza
clean:
	rm -rf $(OUT_PATH)

# Make info para ver variables
info:
	@echo Host System: $(SYSTEM)     $(OS)
	@echo Sources: $(SOURCES)
	@echo Sources Path: $(SRC_PATH)
	@echo Includes Paths: ${INC_PATH}
	@echo Objets: $(OBJS)
	@echo Objets files: ${OBJ_FILES}
	@echo Objets Path: ${OBJ_PATH}


# Regla para flashar el micro con el programador seleccionado
flash:
	avrdude -C ${CONF_PATH}$(CD)avrdude.conf -p ${MCU} -c $(PROGRAMER) -P ${PORT} -b ${BRATE} -D -U flash:w:$(OUT_PATH)$(CD)${TARGET}.hex:i

# Regla para flashar el bootloader con un usbasp
flash-bootloader:
	avrdude -F -v -p ${MCU} -c usbasp -P /dev/usbasp -b ${BRATE} -e -U efuse:w:0xFD:m -U hfuse:w:0xDA:m -U lfuse:w:0xFF:m -U lock:w:0x0F:m
	avrdude -F -v -p ${MCU} -c usbasp -P /dev/usbasp -b ${BRATE} -D -u -U flash:w:$(shell pwd)/tools/${BOOTLOADER}:i -U lock:w:0x0F:m

# Regla para instalar las configuraciones de Udev para USBasp
install:
	sudo cp $(shell pwd)/tools/USBasp.rules /etc/udev/rules.d/ && sudo /etc/init.d$(CD)udev restart

# Pre-requisito para poder compilar, es que existan los directorios de salida, si no existen, se crean
$(OUT_PATH):
	mkdir -p $(OUT_PATH)
	mkdir -p $(OBJ_PATH)
