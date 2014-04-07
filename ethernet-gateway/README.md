## Internet of things board (aka Ethernet Gateway)

- derived from http://kehribar.me/hardware/ethernetGateway/

### Board mods (rev 0.3 PCB)

- cut power trace on underside, wire to header if desired
- cut trace to CTS and rewire to RTS

### Bootloader

Build optiboot for 8MHz and 57600 baud  (source at https://code.google.com/p/optiboot/)
```
make MCU_TARGET=atmega328p AVR_FREQ=8000000L TIMEOUT_MS=12000 BAUD_RATE=57600
```

### Program with bus pirate
```
avrdude -c stk500v2 -p m328p -P /dev/tty.usbserial-A501BZQP -v -U flash:w:optiboot_atmega328.hex 
```

### Set fuses
```
avrdude -c stk500v2 -p m328p -P /dev/tty.usbserial-A501BZQP -v -U lfuse:w:0xe2:m -U hfuse:w:0xde:m -U efuse:w:0x05:m


avrdude: safemode: lfuse reads as E2
avrdude: safemode: hfuse reads as DE
avrdude: safemode: efuse reads as 5
```


### Invert CTS using windows ft_prog utility


### Setup Arduino environment
Add entry to boards.txt for 8MHz/57600 baud

```
##############################################################
uno8.name=Arduino Uno (Internal Oscillator)
uno8.upload.protocol=arduino
uno8.upload.maximum_size=32256
uno8.upload.speed=57600
uno8.bootloader.low_fuses=0xe2
uno8.bootloader.high_fuses=0xde
uno8.bootloader.extended_fuses=0x05
uno8.bootloader.path=optiboot_8MHz
uno8.bootloader.file=optiboot_8MHz_atmega328.hex
uno8.bootloader.unlock_bits=0x3F
uno8.bootloader.lock_bits=0x0F
uno8.build.mcu=atmega328p
uno8.build.f_cpu=8000000L
uno8.build.core=arduino
uno8.build.variant=standard

##############################################################
```
