#ifndef ROOM
#define ROOM

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Room{
 public:
  Room();
  void listExits();
  void listItems();
 protected:
  vector<char*>* exits = new vector<char*>*();
  vector<Item*>* items = new vector<Item*>*();
};

#endif
