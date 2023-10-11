#ifndef ITEM
#define ITEM

#include <iostream>
#include <cstring>

class Item{
 public:
  Item(char* nameIN);
  char name[80];
  char* getName();
};

#endif
