EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:7805
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_01X02 P1
U 1 1 55B99439
P 3850 3100
F 0 "P1" H 3850 3250 50  0000 C CNN
F 1 "CONN_01X02" V 3950 3100 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 3850 3100 60  0001 C CNN
F 3 "" H 3850 3100 60  0000 C CNN
	1    3850 3100
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X02 P2
U 1 1 55B99499
P 5400 3100
F 0 "P2" H 5400 3250 50  0000 C CNN
F 1 "CONN_01X02" V 5500 3100 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 5400 3100 60  0001 C CNN
F 3 "" H 5400 3100 60  0000 C CNN
	1    5400 3100
	1    0    0    -1  
$EndComp
$Comp
L 78L05 U1
U 1 1 55B9979F
P 4650 3100
F 0 "U1" H 4800 2904 60  0000 C CNN
F 1 "78L05" H 4650 3300 60  0000 C CNN
F 2 "WorkshopVregs:TO-220_Neutral123_Vertical" H 4650 3100 60  0001 C CNN
F 3 "" H 4650 3100 60  0000 C CNN
	1    4650 3100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 55B997CB
P 4650 3550
F 0 "#PWR01" H 4650 3300 50  0001 C CNN
F 1 "GND" H 4650 3400 50  0000 C CNN
F 2 "" H 4650 3550 60  0000 C CNN
F 3 "" H 4650 3550 60  0000 C CNN
	1    4650 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 3050 4050 3050
Wire Wire Line
	5050 3050 5200 3050
Wire Wire Line
	4650 3350 4650 3550
Wire Wire Line
	4050 3150 4300 3150
Wire Wire Line
	4300 3150 4300 3400
Wire Wire Line
	4300 3400 5000 3400
Connection ~ 4650 3400
Wire Wire Line
	5200 3150 5000 3150
Wire Wire Line
	5000 3150 5000 3400
$EndSCHEMATC
