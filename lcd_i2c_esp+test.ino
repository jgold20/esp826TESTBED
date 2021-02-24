/*
 Name:		Sketch13.ino
 Created:	2/24/2021 12:30:04 PM
 Author:	jgold
*/



#include <WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


// lcd setup
int lcdCols = 16;
int lcdRows = 2;

// I2C display (uses same data protocol as atlas sensor
LiquidCrystal_I2C lcd(0x3F, lcdCols, lcdRows);
byte ad;

// the setup function runs once when you press reset or power the board
void setup() {
	Wire.begin();
    i2c_scanner();

	Serial.begin(115200);
    lcd.init();
    lcd.backlight();
	
}


// the loop function runs over and over again until power down or reset
void loop() {
    
   
    // Scanner should come back with devices found on i2c ports
    //Serial.println("SCANNER COMPLETE");
    lcd.setCursor(0, 0);
    lcd.print("Hello, World!");
    delay(1000);
    // clears the display to print new message
    lcd.clear();

    lcd.setCursor(0, 1);
    lcd.print("Hello, World!");
    delay(1000);
    lcd.clear();

}



// scan for i2c devices on esp module
// Prints out the 0x00 address of I2C device
void i2c_scanner() {
    byte error, address;
    int nDevices;
    Serial.println("Scanning.....");
    nDevices = 0;
    // loop address spaces
    for (address = 1; address < 127; address++) {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();
        if (error == 0) {
            Serial.print("I2C device found at address 0x");
            if (address < 16) {
                Serial.print("0");
            }
            Serial.println(address, HEX);
            nDevices++;
        }
        else if (error == 4) {
            Serial.print("Unknow error at address 0x");
            if (address < 16) {
                Serial.print("0");
            }
            Serial.println(address, HEX);
           
        }
    }
    if (nDevices == 0) {
        Serial.println("No I2C devices found\n");
    }
    else {
        ad = address;
        Serial.println("done\n");
    }
    delay(5000);
}
