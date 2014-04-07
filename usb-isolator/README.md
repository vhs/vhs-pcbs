USB Isolator PCB
================


Notes
-----

This is a very simple PCB so little documentation is needed.  Information
about the isolation can be found in the ADUM3160 [data sheet](http://www.analog.com/en/interface-isolation/digital-isolators/adum3160/products/product.html).

It is VERY important to realise that the power needs to come from a plug
pack and not the computer.  Supplying power to the power input from the
computer removes most of the isolation (data is still isolated).

Note that pin one is not marked on early versions of the PCB. Please refer
to the photo in this repository.

Parts
-----

PCBs are for sale on [Tindie](https://www.tindie.com/products/TomKeddie/usb-isolator-pcb-only/)

All the USB connectors were originally purchased on ebay.

You may be able to get a sample of the ADUM3160BRWZ from Analog Devices.

Ths parts list is below, if someone can supply the part numbers for a common
supplier that would be appreciated.  I don't want to suggest them without
ordering the actual parts and verifying fit.

| Qty | Value | Device | Parts | Description | 
| --- | ----- | ------ | ----- | ----------- | 
| 2 | 10uF | C-EUC0805K | C1, C6 | 10uF 0805 Ceramic Capacitor |
| 4 | 0.1uF | C-EUC0805K | C2, C3, C4, C5 | 0.1uF 0805 Ceramic Capactor |
| 4 | 24R | R-EU_M0805 | R1, R2, R3, R4 | 24R 0805 5% resistor |
| 1 | 10K | R-EU_M0805 | R5 | 10k 0805 5% resistor |
| 1 | 47uF | CPOL-EUD/7343-31W C7 | 47uF 2917 Size "D" Tantalum Capacitor |
| 1 | ADUM3160BRWZ | SO16W | IC1 | Analog Devices ADUM3160BRWZ | 
| 1 | CON-USB-F-2PB | CON-USB-F-2PB | USBOUT | USB Female connector with 2 body pins | 
| 2 | CON-USB-F-MINI-B | CONN_USB_MINI-B | POWER, USBIN | USB Mini Female connector | 
| 1 | PCB_DP_SQUARE-5X5 | DP5050_V1 | USB-ISOLATOR | USB Isolator PCB |
