FAMILY=-mpic14
MCU=-p12f683
CC=sdcc
LD=sdcc
#Ruta propia
#CFLAGS=-I. -I/usr/local/share/sdcc-4.0.0/share/sdcc/non-free
#Ruta default
CFLAGS=-I. -I/usr/local/share/sdcc-4.0.0/share/sdcc/non-free

TARGET = blink

SRCS = blink.c

all:
	${CC} --use-non-free ${FAMILY} ${MCU} ${CFLAGS} -o ${TARGET} ${SRCS}
#	${LD} -o ${TARGET}.elf ${TARGET}.o
#	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.o ${TARGET}.hex
#	${SIZE} -C --mcu=${MCU} ${TARGET}.elf

clean:
	rm -f *.c~ *.h~ *.o *.elf *.hex *.asm
