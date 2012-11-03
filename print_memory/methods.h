//The linked list node
typedef struct node{
  uint8_t arr[4*4*4];
  node *next;
};
const char startChar = 'A';
static uint8_t ascii['z'-startChar+1][3];

node * setList(char *text, uint8_t length);

//helper methods for initializing the 3-byte character bitmaps
void initAscii(char c, uint8_t val[3]){
  for(int i = 0; i < 3; i++){
    ascii[c-startChar][i] = val[i];
  }
}


void initChars(){
  initAscii('L',(uint8_t[3]){ 0xff,
                              0x80,
                              0x80});
  initAscii('i',(uint8_t[3]){ 0x90,
                              0xf4,
                              0x90});
  initAscii('n',(uint8_t[3]){ 0xf0,
                              0x10,
                              0xe0});
  initAscii('k',(uint8_t[3]){ 0xff,
                              0x20,
                              0xd0});
  initAscii('e',(uint8_t[3]){ 0xf8,
                              0xa8,
                              0xb0});
  initAscii('d',(uint8_t[3]){ 0xe0,
                              0x90,
                              0xff});
  initAscii('s',(uint8_t[3]){ 0xb0,
                              0xa8,
                              0xe8});
  initAscii('t',(uint8_t[3]){ 0x10,
                              0xf8,
                              0x10});
  initAscii('N',(uint8_t[3]){ 0xff,
                              0x01,
                              0xff});
  initAscii('Y',(uint8_t[3]){ 0x07,
                              0xf8,
                              0x07});
  initAscii('C',(uint8_t[3]){ 0xff,
                              0x81,
                              0x81});
}
