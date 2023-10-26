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
  Room(char* nameIN);
  char* getName();
  void listExits();
  bool setExit(char* direction, Room* toRoom);
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
