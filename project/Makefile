# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include -L../lib

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: main.elf 

#additional rules for files
main.elf: ${COMMON_OBJECTS} main.o p2_interrupt_handler.o led.o switches.o buzzer.o buzzerState.o lcdDisplay.o wdt_handler.o stateMachineAssembly.o ../project/lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lLcd -lp2sw -lTimer -lShape -lCircle

load: main.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf
