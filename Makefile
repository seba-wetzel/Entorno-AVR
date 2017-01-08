# Variables del microprocesador elegido
MCU=atmega328p
F_CPU=16000000
ARCH=avr
# Variables de programacion (el baudrate depende del bootloader del arduino usado)
PORT=/dev/USBasp
BRATE=115200
# Variable del programador usado, este puede ser un arduino como un usbasp
PROGRAMER= usbasp

# Variables de compilador
CC=$(TOOLS_PATH)/avr-gcc
OBJCOPY=$(TOOLS_PATH)/avr-objcopy
CFLAGS=-std=c11 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU}
SIZE=$(TOOLS_PATH)/avr-size
SFLAGS=-C

# Variables para generar el nombre del binario
EJECUTABLE := $(notdir $(shell pwd))
TARGET=$(EJECUTABLE)

# Variables de directorios
SRC_PATH := src
INC_PATH := inc
OUT_PATH := out
OBJ_PATH := $(OUT_PATH)/obj
SOURCES := $(wildcard $(SRC_PATH)/*.c)
CONF_PATH= $(shell pwd)/conf
TOOLS_PATH= $(shell pwd)/tools/$(ARCH)/bin
OBJS := $(subst $(SRC_PATH),$(OBJ_PATH),$(SOURCES:.c=.o))
OBJ_FILES := $(notdir $(OBJS))
vpath %.c $(SRC_PATH)
vpath %.o $(OBJ_PATH)

# Regla all para compatibilizar con eclipse out of the box
all: $(TARGET)

# Regla de linkeo y generacion de direcctorios de salida (si no existen)
$(TARGET): $(OBJ_PATH)
	${CC} ${CFLAGS} -I $(INC_PATH) -o $(OUT_PATH)/$(TARGET).bin  ${SOURCES}
	${OBJCOPY} -j .text -j .data -O ihex $(OUT_PATH)/$(TARGET).bin  $(OUT_PATH)/${TARGET}.hex
	${SIZE} ${SFLAGS} $(OUT_PATH)/$(TARGET).bin

# Regla clean
clean:
	rm -rf $(OUT_PATH)

# Make info para ver variables
info:
	@echo $(SOURCES)
	@echo $(OBJS)

# Regla para flashar el micro con el programador seleccionado
flash:
	avrdude -C $(CONF_PATH)/avrdude.conf -v -p ${MCU} -c $(PROGRAMER) -P ${PORT} -b ${BRATE} -D -U flash:w:$(OUT_PATH)/${TARGET}.hex:i

# Regla para instalar las configuraciones de Udev para USBasp
install:
	sudo cp $(shell pwd)/tools/USBasp.rules /etc/udev/rules.d/ && sudo /etc/init.d/udev restart
	
# Pre-requisito para poder compilar, es que existan los directorios de salida, si no existen, se crean
$(OBJ_PATH):
	mkdir -p $(OUT_PATH)
	mkdir -p $(OBJ_PATH)

