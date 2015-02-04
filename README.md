# mini_CNC
AVR code for ATMega32u2 based mini CNC drill press.
For a detailed description of this project, see 
https://acidbourbon.wordpress.com/2015/02/01/semi-automated-drill-press-table-for-pcb-manufacture/

- Prerequisites (name of Ubuntu/Debian packages):
avr-libc
gcc-avr
dfu-programmer

on a debian based Linux machine you can just 
````bash
sudo apt-get install avr-libc gcc-avr dfu-programmer
````


- compilation instructions (Linux shell):

get the code (if you downloaded and unpacked the .zip file, you can obviously ignore skip this step)

````bash
cd /some/empty/directory/
git clone https://github.com/acidbourbon/mini_CNC
````
get the LUFA source code, and put it in ./LUFA/LUFA-130303/
finally compile and program the microcontroller code

````bash
mkdir LUFA
cd LUFA
wget http://www.github.com/abcminiuser/lufa/archive/LUFA-130303.zip
unzip LUFA-130303.zip
mv lufa-LUFA-130303 LUFA-130303
cd ..
cd mini_CNC/
make
make program
````

Pull the ATMega32u2 into reset and wait 2-3 seconds before programming.
If dfu-programmer is not allowed to access the ATMega32u2 chip, try
````bash
sudo make program
````

You probably should be able to port this software to ATMega32u4, if you change the TARGET parameter in the makefile.


