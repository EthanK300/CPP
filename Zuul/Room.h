#ifndef ROOM
#define ROOM

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"

using namespace std;

class Room{
 public:
  Room(vector<Item*>* itemsIN, map<char*, Room*>* exitsIN);
  char* getName();
  void listExits();
  vector<Item*>* getItems();
  map<char*, Room*>* getExits();
  void listItems();
  bool removeItem(Item* item);
  bool addItem(Item* item);
  char name[80];
 protected:
  map<char*, Room*>* exits = new map<char*, Room*>();
  vector<Item*>* items = new vector<Item*>();
  
};

#endif
