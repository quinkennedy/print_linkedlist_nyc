#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"
#include "Stream.h"
#include <avr/pgmspace.h>

uint8_t start;

/**
 * Declare which pins to communicate to the printer over
 */
int printer_RX_Pin = 5; // green wire
int printer_TX_Pin = 6; // yellow wire
const int maxWidth = 384;
const int bytesWidth = maxWidth/8;
const int bytesMemory = 2000;
const int maxHeight = bytesMemory/bytesWidth;

/**
 * Initialize the thermal printer
 */
Adafruit_Thermal printer(printer_RX_Pin, printer_TX_Pin);

void setup(){
  printer.begin();
  //printer.printBitmap(maxWidth, 1, bmp);
  printer.println("Hello");
  int square = sqrt(bytesMemory*8);
  printer.printBitmap(square, bytesMemory*8/square, ((const uint8_t*)0), false);
  //printer.feed(1);
  //printer.printBitmap(maxWidth, 32, bitmap, false);
  //printer.println((long)bitmap);
  printer.println("Bye");
}

void loop(){}