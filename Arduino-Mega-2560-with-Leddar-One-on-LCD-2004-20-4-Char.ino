/*
** This sketch is a combination of:
** Simple Leddar(TM) Example, using a LeddarOne.
** Language: Arduino
** 
** This program displays on a LCD screen the distance
** and returned signal amplitude of the detection
** 
**   Shields used:
** RS-485 Shield
** LCD Keypad Shield
** 
**
** This example code is in the public domain.
**
** AND
**
** Example Arduino sketch for SainSmart I2C LCD2004 adapter for HD44780 LCD screens
** Readily found on eBay or http://www.sainsmart.com/ 
** The LCD2004 module appears to be identical to one marketed by YwRobot
**
** Edward Comer
** LICENSE: GNU General Public License, version 3 (GPL-3.0)
**
** sain_lcd_2.ino
** Simplified and modified by Andrew Scott for Arudino 1.0.1, Arudino Uno R3.
** NOTE: I2C pins are A4 SDA, A5 SCL
** Don't forget to use the new LiquidCrystal Library.
** 
** Arduino Mega 2560 with Leddar One on LCD 2004 20+4 Char.ino
** My particular LCD uses 0x27 and SDA to SDA - SCL to SCL
** Lance Brummett
** LICENSE: GNU General Public License, version 3 (GPL-3.0)
 
*/

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Leddar.h>

#define I2C_ADDR    0x27  // Define I2C Address where the SainSmart LCD is
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

LeddarOne Leddar1(115200,1);
//Baudrate = 115200
//Modbus slave ID = 01
// NOTE: If your RS-485 shield has a Tx Enable (or DE) pin, 
// use: Leddar Leddar1(115200,1, TxEnablePinNumber, 1);

LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup()
{
 Serial.begin(115200); //Opens serial connection at 115200bps.
 lcd.begin (20,4);
// Switch on the backlight
 lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
 lcd.setBacklight(HIGH);

//Initialize Leddar 
	Leddar1.init();
}

void loop()
{


   //This is the actual lcd code posted on arduino's forums - that finally worked for me
   // many thanks.
   //Position cursor and write some text
// lcd.home ();                   // go to the first line, first character
// lcd.print("SainSmart I2C tester");  
// lcd.setCursor ( 0, 1 );        // go to the 2nd line
// lcd.print("It's Working!");
// lcd.setCursor ( 0, 2 );        // go to the third line
// lcd.print("Sainsmarts docs suck");
// lcd.setCursor ( 0, 3 );        // go to the fourth line
// lcd.print("Nice LCD Though. ");


	unsigned int Distance = 0;
	unsigned int Amplitude = 0;

	char result = Leddar1.getDetections();
	if (result >= 0)
	{
		// Show the first detection only
		Distance = Leddar1.Detections[0].Distance;
		Amplitude = Leddar1.Detections[0].Amplitude;

		//Serial.print("Distance: "); Serial.println(Distance); 
		//Serial.print("Amplitude: "); Serial.println(Amplitude); 
    lcd.home ();
		// this was leddar code lcd.setCursor(0,0);
		lcd.print("Distance:        ");
		lcd.setCursor(10,0);
		lcd.print(Distance);
		lcd.setCursor(0,1);
		lcd.print("Amplitude:        ");
		lcd.setCursor(11,1);
		lcd.print(Amplitude);    
	}
	else
	{
		//Serial.print("Error: "); Serial.println((int)result); 
		lcd.setCursor(0,0);
		lcd.print("Error: "); lcd.print((int)result); lcd.print("        ");
		lcd.setCursor(0,1);
		lcd.print("No LeddarOne Found");
	}
	delay(50);
}



