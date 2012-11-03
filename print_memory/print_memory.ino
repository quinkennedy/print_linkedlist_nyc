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
const char startChar = 'A';

static uint8_t ascii['z'-startChar+1][3];

void initAscii(char c, uint8_t val[3]){
  for(int i = 0; i < 3; i++){
    ascii[c-startChar][i] = val[i];
  }
}


void initChars(){
initAscii('L',(uint8_t[3]){
  0xff,
  0x80,
  0x80});
initAscii('i',(uint8_t[3]){
    0x90,
    0xf4,
    0x90});
initAscii('n',(uint8_t[3]){
    0xf0,
    0x10,
    0xe0});
initAscii('k',(uint8_t[3]){
    0xff,
    0x20,
    0xd0});
initAscii('e',(uint8_t[3]){
    0xf8,
    0xa8,
    0xb0});
initAscii('d',(uint8_t[3]){
    0xe0,
    0x90,
    0xff});
initAscii('s',(uint8_t[3]){
    0xb0,
    0xa8,
    0xe8});
initAscii('t',(uint8_t[3]){
    0x10,
    0xf8,
    0x10});
initAscii('N',(uint8_t[3]){
    0xff,
    0x01,
    0xff});
initAscii('Y',(uint8_t[3]){
    0x07,
    0xf8,
    0x07});
initAscii('C',(uint8_t[3]){
    0xff,
    0x81,
    0x81});
    }

/**
 * Initialize the thermal printer
 */
Adafruit_Thermal printer(printer_RX_Pin, printer_TX_Pin);

void setup(){
  initChars();
  printer.begin();
  //printer.printBitmap(8, 14*4, text, false);
  setList("LinkedList NYC",14);//"LinkedList NYC", 14);//"LinkedList NYC", 14, 0, false);
  printer.feed(1);
  return;
  //printer.printBitmap(maxWidth, 1, bmp);
  printer.println("Hello");
  int square = sqrt(bytesMemory*8);
  printer.printBitmap(square, bytesMemory*8/square, ((const uint8_t*)0), false);
  //printer.feed(1);
  //printer.printBitmap(maxWidth, 32, bitmap, false);
  //printer.println((long)bitmap);
  printer.println("Bye");
}

uint8_t getDstI(uint8_t i){
  return i/8*4 + 3 - ((i%8)/2);
}

void setList(char *text, uint8_t length){
  uint8_t arr[4*4*3];
  uint8_t *src = ascii[(*(text+length-1))-startChar];
  for(uint8_t i = 0; i < 4*4*3*2; i++){
    arr[getDstI(i)] >>= 4;
    if ((*(text+length-1)) != ' ' && (((*(src+(i/(4*8)))) >> (i%8)) & 1) == 1){
      arr[getDstI(i)] |= 0xf0;
    } else {
      arr[getDstI(i)] &= 0x0f;
    }
  }
  if (length > 1){
    setList(text, length - 1);
  } else {
    printer.printBitmap(4*8, 14*4*4, arr, false);
    //printer.printBitmap(4*8, 3*4*4, start, false);
  }
  //printer.printBitmap(32,16, arr, false);
}

void loop(){}
