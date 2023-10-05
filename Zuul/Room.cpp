#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"

using namespace std;

Room::Room(){

}

void Room::listExits(Room* currentRoom){
  cout << "Exits: " << endl;
  for(map<char*, Room*>::iterator it = exits->begin(); it != exits->end(); ++it){
    cout << "Exit direction: " << exits(*it) << " To room: " << exits->at(*it) << endl;
  }
}

void Room::listItems(Room* currentRoom){
  for(vector<Item*>::iterator it = items->begin(); it != items->end(); ++it){
    cout << "Name: " << (*it)->getName() << endl;
  }
}

bool Room::removeItem(Room* currentRoom, Item* item){
  for(vector<Item*>::iterator it = items->begin(); it != items->end(); ++it){
    if(!strcmp((*it)->getName(), item->getName())){
      delete *it;
      items->erase(it);
      return true;
    }else{
      return false;
    }
  }
}

bool Room::addItem(Room* currentRoom, Item* item){
  items->pushback(item);
  return True;
}
