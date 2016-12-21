# Variables del microprocesador elegido
MCU=atmega328p
F_CPU=16000000
ARCH=avr
# Variables de programacion (el baudrate depende del bootloader del arduino usado)
PORT=/dev/ttyACM0
BRATE=115200

# Variables de compilador
CC=$(TOOLS_PATH)/avr-gcc
OBJCOPY=$(TOOLS_PATH)/avr-objcopy
CFLAGS=-std=c11 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU}
SIZE=$(TOOLS_PATH)/avr-size
SFLAGS=-C

# Variables para generar el nombre del binario
EJECUTABLE := $(notdir $(shell pwd))
TARGET=$(EJECUTABLE)

#variables de directorios
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

#regla all para compatibilizar con eclipse out of the box
all: $(TARGET)

#regla de linkeo y generacion de direcctorios de salida (si no existen)
$(TARGET): $(OBJ_PATH)
	${CC} ${CFLAGS} -I $(INC_PATH) -o $(OUT_PATH)/$(TARGET).bin  ${SOURCES}
	${OBJCOPY} -j .text -j .data -O ihex $(OUT_PATH)/$(TARGET).bin  $(OUT_PATH)/${TARGET}.hex
	${SIZE} ${SFLAGS} $(OUT_PATH)/$(TARGET).bin

#regla clean
clean:
	rm -rf $(OUT_PATH)

#make info para ver variables
info:
	@echo $(SOURCES)
	@echo $(OBJS)


flash:
	avrdude -C $(CONF_PATH)/avrdude.conf -v -p ${MCU} -c arduino -P ${PORT} -b ${BRATE} -D -U flash:w:$(OUT_PATH)/${TARGET}.hex:i

#pre-requisito para poder compilar, es que existan los directorios de salida, si no existen, se crean
$(OBJ_PATH):
	mkdir -p $(OUT_PATH)
	mkdir -p $(OBJ_PATH)
