

typedef struct node{
  uint8_t arr[4*4*4];
  node *next;
};

node * setList(char *text, uint8_t length);
