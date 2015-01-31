EESchema Schematic File Version 2  date Sat 02 Nov 2013 03:39:31 PM CET
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
LIBS:special
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
EELAYER 43  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title ""
Date "2 nov 2013"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Notes Line
	8500 1200 2900 1200
Wire Notes Line
	8500 1200 8500 4500
Wire Notes Line
	8500 4500 2900 4500
Wire Notes Line
	2900 4500 2900 1200
Wire Notes Line
	4600 4600 4600 5450
Wire Notes Line
	3550 4750 5100 4750
Connection ~ 4700 4050
Wire Wire Line
	4550 4050 5950 4050
Wire Wire Line
	6850 5000 6650 5000
Wire Wire Line
	7450 5000 7650 5000
Wire Wire Line
	7450 5300 7650 5300
Connection ~ 3800 3000
Wire Wire Line
	4050 3000 3550 3000
Wire Wire Line
	3550 3000 3550 4300
Wire Wire Line
	7100 3000 7100 4300
Connection ~ 7650 2650
Connection ~ 7650 3600
Wire Wire Line
	7850 3600 6200 3600
Wire Wire Line
	7650 1600 7650 2100
Wire Wire Line
	6750 1700 6750 1600
Wire Wire Line
	6750 2300 7350 2300
Wire Wire Line
	7650 3600 7650 3200
Wire Wire Line
	7100 3000 7350 3000
Wire Wire Line
	6200 3600 6200 3500
Wire Wire Line
	7650 2800 7650 2500
Wire Wire Line
	6750 2800 6750 2200
Connection ~ 6750 2300
Wire Wire Line
	6750 3200 6750 3600
Connection ~ 6750 3600
Wire Wire Line
	6750 1600 7850 1600
Connection ~ 7650 1600
Wire Wire Line
	7850 2650 7650 2650
Wire Wire Line
	5450 2650 5250 2650
Connection ~ 5250 1600
Wire Wire Line
	5450 1600 4350 1600
Connection ~ 4350 3600
Wire Wire Line
	4350 3200 4350 3600
Connection ~ 4350 2300
Wire Wire Line
	4350 2800 4350 2200
Wire Wire Line
	5250 2800 5250 2500
Wire Wire Line
	3800 3500 3800 3600
Wire Wire Line
	4950 3000 4700 3000
Wire Wire Line
	5250 3600 5250 3200
Wire Wire Line
	4350 2300 4950 2300
Wire Wire Line
	4350 1600 4350 1700
Wire Wire Line
	5250 1600 5250 2100
Wire Wire Line
	3800 3600 5450 3600
Connection ~ 5250 3600
Connection ~ 5250 2650
Wire Wire Line
	6450 3000 5950 3000
Wire Wire Line
	5950 3000 5950 4050
Wire Wire Line
	4700 3000 4700 4050
Connection ~ 6200 3000
Wire Wire Line
	6850 5300 6650 5300
Wire Notes Line
	7550 5450 7550 4750
Wire Notes Line
	7550 5450 6750 5450
Wire Notes Line
	6750 5450 6750 4750
Wire Notes Line
	6750 4750 7550 4750
Wire Wire Line
	7100 4300 3400 4300
Connection ~ 3550 4300
Wire Notes Line
	4000 4600 4000 5450
Wire Notes Line
	5400 5350 4700 5350
Text Notes 3250 1400 0    60   ~ 0
1/2 bipolar stepper motor driver
Text Notes 4700 5350 0    60   ~ 0
kills your FETs! (don't do)
Text Notes 4200 5350 0    60   ~ 0
5V
Text Notes 3700 5350 0    60   ~ 0
5V
Text Notes 4200 5200 0    60   ~ 0
0V
Text Notes 3700 5200 0    60   ~ 0
0V
Text Notes 3700 5050 0    60   ~ 0
0V
Text Notes 4200 5050 0    60   ~ 0
5V
Text Notes 4700 5200 0    60   ~ 0
no current
Text Notes 4700 5050 0    60   ~ 0
reverse current coil 1
Text Notes 4700 4900 0    60   ~ 0
forward current coil 1
Text Notes 4200 4900 0    60   ~ 0
0V
Text Notes 3700 4900 0    60   ~ 0
5V
Text Notes 4750 4700 0    60   ~ 0
result
Text Notes 4150 4700 0    60   ~ 0
cc 1B
Text Notes 3600 4700 0    60   ~ 0
cc 1A
Text GLabel 3400 4300 0    60   Input ~ 0
cc 1A
Text GLabel 4550 4050 0    60   Input ~ 0
cc 1B
Text Notes 6700 4650 0    60   ~ 0
bipolar stepper motor
$Comp
L INDUCTOR L?
U 1 1 52750B87
P 7150 5000
F 0 "L?" V 7100 5000 40  0000 C CNN
F 1 "Motor Coil 1" V 7250 5000 40  0000 C CNN
	1    7150 5000
	0    -1   -1   0   
$EndComp
Text GLabel 6650 5000 0    60   Input ~ 0
coil 1 A
Text GLabel 7650 5000 2    60   Input ~ 0
coil 1 B
Text GLabel 7650 5300 2    60   Input ~ 0
coil 2 B
Text GLabel 6650 5300 0    60   Input ~ 0
coil 2 A
Text GLabel 5450 2650 2    60   Output ~ 0
coil 1 A
$Comp
L MOSFET_N Q?
U 1 1 527509DA
P 7550 3000
F 0 "Q?" H 7560 3170 60  0000 R CNN
F 1 "IRF530N" H 7560 2850 60  0000 R CNN
	1    7550 3000
	1    0    0    -1  
$EndComp
$Comp
L MOSFET_P Q?
U 1 1 527509D9
P 7550 2300
F 0 "Q?" H 7550 2490 60  0000 R CNN
F 1 "IRF9Z34N" H 7550 2120 60  0000 R CNN
	1    7550 2300
	1    0    0    1   
$EndComp
$Comp
L R R?
U 1 1 527509D8
P 6750 1950
F 0 "R?" V 6830 1950 50  0000 C CNN
F 1 "10k" V 6750 1950 50  0000 C CNN
	1    6750 1950
	1    0    0    -1  
$EndComp
$Comp
L MOSFET_N Q?
U 1 1 527509D7
P 6650 3000
F 0 "Q?" H 6660 3170 60  0000 R CNN
F 1 "2N7000" H 6660 2850 60  0000 R CNN
	1    6650 3000
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 527509D6
P 6200 3250
F 0 "R?" V 6280 3250 50  0000 C CNN
F 1 "10k" V 6200 3250 50  0000 C CNN
	1    6200 3250
	1    0    0    -1  
$EndComp
Text GLabel 7850 3600 2    60   Input ~ 0
GND
Text GLabel 7850 1600 2    60   Input ~ 0
+18V
Text GLabel 7850 2650 2    60   Output ~ 0
coil 1 B
$Comp
L INDUCTOR L?
U 1 1 52750943
P 7150 5300
F 0 "L?" V 7100 5300 40  0000 C CNN
F 1 "Motor Coil 2" V 7250 5300 40  0000 C CNN
	1    7150 5300
	0    -1   -1   0   
$EndComp
Text GLabel 5450 1600 2    60   Input ~ 0
+18V
Text GLabel 5450 3600 2    60   Input ~ 0
GND
$Comp
L R R?
U 1 1 5275069D
P 3800 3250
F 0 "R?" V 3880 3250 50  0000 C CNN
F 1 "10k" V 3800 3250 50  0000 C CNN
	1    3800 3250
	1    0    0    -1  
$EndComp
$Comp
L MOSFET_N Q?
U 1 1 527505B0
P 4250 3000
F 0 "Q?" H 4260 3170 60  0000 R CNN
F 1 "2N7000" H 4260 2850 60  0000 R CNN
	1    4250 3000
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 527505A7
P 4350 1950
F 0 "R?" V 4430 1950 50  0000 C CNN
F 1 "10k" V 4350 1950 50  0000 C CNN
	1    4350 1950
	1    0    0    -1  
$EndComp
$Comp
L MOSFET_P Q?
U 1 1 52750587
P 5150 2300
F 0 "Q?" H 5150 2490 60  0000 R CNN
F 1 "IRF9Z34N" H 5150 2120 60  0000 R CNN
	1    5150 2300
	1    0    0    1   
$EndComp
$Comp
L MOSFET_N Q?
U 1 1 52750581
P 5150 3000
F 0 "Q?" H 5160 3170 60  0000 R CNN
F 1 "IRF530N" H 5160 2850 60  0000 R CNN
	1    5150 3000
	1    0    0    -1  
$EndComp
$EndSCHEMATC
