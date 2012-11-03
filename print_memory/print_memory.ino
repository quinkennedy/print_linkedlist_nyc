#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"
#include "methods.h"

/**
 * Declare which pins to communicate to the printer over
 */
int printer_RX_Pin = 5; // green wire
int printer_TX_Pin = 6; // yellow wire



/**
 * Initialize the thermal printer
 */
Adafruit_Thermal printer(printer_RX_Pin, printer_TX_Pin);

void setup(){
  initChars();
  printer.begin();
  node *root = setList("LinkedList NYC", 14);
  printer.printBitmap(4*8, 14*4*4+14, (uint8_t*)root, false);
  printer.feed(2);
}

uint8_t getDstI(uint8_t i){
  return i/8*4 + 3 - ((i%8)/2);
}

node * setList(char *text, uint8_t length){
  node *curr = new node;
  uint8_t *src = ascii[(*(text))-startChar];
  for(uint8_t i = 0; i < 4*4*4*2; i++){
    curr->arr[getDstI(i)] >>= 4;
    if ((*(text)) != ' ' && 
        (i < 4*4*3*2) &&
        (((*(src+(i/(4*8)))) >> (i%8)) & 1) == 1){
      curr->arr[getDstI(i)] |= 0xf0;
    } else {
      curr->arr[getDstI(i)] &= 0x0f;
    }
  }
  if (length > 1){
    curr->next = setList(text + 1, length - 1);
  }
  return curr;
}

void loop(){}
