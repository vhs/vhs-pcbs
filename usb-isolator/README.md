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

| Qty | Value | Device | Package | Parts | Description | 
| --- | ----- | ------ | ------- | ----- | ----------- | 
| 4 | 0.1uF | C-EUC0805K | C0805K | C2, C3, C4, C5 | CAPACITOR, European symbol | 
| 1 | 10K | R-EU_M0805 | M0805 | R5 | RESISTOR, European symbol | 
| 2 | 10uF | C-EUC0805K | C0805K | C1, C6 | CAPACITOR, European symbol | 
| 4 | 24R | R-EU_M0805 | M0805 | R1, R2, R3, R4 | RESISTOR, European symbol | 
| 1 | 47uF | CPOL-EUD/7343-31W | D/7343-31W | C7 | POLARIZED CAPACITOR, European symbol | 
| 1 | ADUM3160BRWZ | ADUM3160BRWZ | SO16W | IC1 |  | 
| 1 | CON-USB-F-2PB | CON-USB-F-2PB | CONN_USB_A_F | USBOUT | USB Female connector with 2 body pins | 
| 2 | CON-USB-F-MINI-B | CON-USB-F-MINI-B | CONN_USB_MINI-B | POWER, USBIN | USB Female connector | 
| 1 | PCB_DP_SQUARE-5X5 | PCB_DP_SQUARE-5X5 | DP5050_V1 | USB-ISOLATOR | USb Isolator PCB |
