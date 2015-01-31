# mini_CNC
AVR code for ATMega32u2 based mini CNC drill press.
For a detailed description of this project, see 
https://acidbourbon.wordpress.com/?p=354

- Prerequisites (name of Ubuntu/Debian packages):
avr-libc
gcc-avr
dfu-programmer

on a debian based Linux machine you can just 
````bash
sudo apt-get install avr-libc gcc-avr dfu-programmer
````


- compilation instructions (Linux shell):

````bash
cd /some/empty/directory/
git clone https://github.com/acidbourbon/mini_CNC
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



