TARGET = rfid_hid_test
EXTRA_OBJS =  LiquidCrystal.cpp.o TimerOne.cpp.o
SERIAL_PORT=$(wildcard /dev/tty.usb*)

ARDUINO = /Applications/Arduino.app/Contents/Resources/Java
# Diecimila
#MCU=atmega168
#PROGRAMMER=arduino
#ARDUINO_FLAGS = -DF_CPU=16000000L -MMD -DUSB_VID=null -DUSB_PID=null -I$(ARDUINO)/hardware/arduino/variants/standard
# Leonardo (32u4)
MCU = atmega32u4
PROGRAMMER=avr109
BAUD_RATE=57600
ARDUINO_FLAGS = -DF_CPU=16000000L -MMD -DUSB_VID=0x2341 -DUSB_PID=0x8036 -I$(ARDUINO)/hardware/arduino/variants/leonardo
# Uno
#MCU=atmega328p
#BAUD_RATE=115200
#PROGRAMMER=arduino
#ARDUINO_FLAGS = -DF_CPU=16000000L -MMD -DUSB_VID=null -DUSB_PID=null -DARDUINO=105 -I$(ARDUINO)/hardware/arduino/variants/standard -I$(ARDUINO)/libraries

CPPFLAGS = -g -Os -Wall -fno-exceptions -ffunction-sections -fdata-sections -mmcu=$(MCU) $(ARDUINO_FLAGS) -DARDUINO=105 -I$(ARDUINO)/hardware/arduino/cores/arduino -I$(ARDUINO)/libraries
LDFLAGS = -Os -Wl,--gc-sections -mmcu=$(MCU)
LDLIBS = -lm
OBJCOPYEEPFLAGS = -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0
OBJCOPYFLAGS = -O ihex -R .eeprom

CC = $(ARDUINO)/hardware/tools/avr/bin/avr-gcc
CXX = $(ARDUINO)/hardware/tools/avr/bin/avr-g++
OBJCOPY = $(ARDUINO)/hardware/tools/avr/bin/avr-objcopy
AVRDUDE = $(ARDUINO)/hardware/tools/avr/bin/avrdude

ARDUINO_OBJS = malloc.c.o realloc.c.o WInterrupts.c.o wiring.c.o wiring_analog.c.o wiring_digital.c.o wiring_pulse.c.o wiring_shift.c.o CDC.cpp.o HardwareSerial.cpp.o HID.cpp.o IPAddress.cpp.o main.cpp.o new.cpp.o Print.cpp.o Stream.cpp.o Tone.cpp.o USBCore.cpp.o WMath.cpp.o WString.cpp.o SoftwareSerial.cpp.o HardwareSerial.cpp.o

VPATH=$(shell find /Applications/Arduino.app/Contents/Resources/Java -name '*.c*' | xargs -n 1 dirname | uniq)

.SUFFIXES: .c.o .cpp.o .eep

$(TARGET).hex : $(TARGET).eep $(TARGET).elf


$(TARGET).elf : $(TARGET).o $(ARDUINO_OBJS) $(EXTRA_OBJS)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

rfid_hid_test.o : rfid_hid_test.cpp rfid_hid_test.ino

%.c.o  : %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

%.cpp.o  : %.cpp
	$(CXX) -c $(CPPFLAGS) -I/Applications/Arduino.app/Contents/Resources/Java/libraries/SoftwareSerial $(CXXFLAGS) $< -o $@

%.eep : %.elf
	$(OBJCOPY) $(OBJCOPYEEPFLAGS) $< $@

%.hex : %.elf
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

clean :
	rm -f *.o *.hex *.elf *.eep

install : $(TARGET).hex
	$(AVRDUDE) -C$(ARDUINO)/hardware/tools/avr/etc/avrdude.conf -p$(MCU) -c$(PROGRAMMER) -P$(SERIAL_PORT) -b$(BAUD_RATE) -D -Uflash:w:$(TARGET).hex:i


