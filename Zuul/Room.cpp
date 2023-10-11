#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"

using namespace std;

Room::Room(vector<Item*>* itemsIN, map<char*, Room*>* roomsIN){
  for(vector<Item*>::iterator it = itemsIN->begin(); it != itemsIN->end(); ++it){
    items->push_back((*it));
  }
  for(map<Room*>::iterator it = roomsIN->begin(); it != roomsIN->end(); ++it){
    exits->push_back();
  }
}

void Room::listExits(){
  cout << "Exits: " << endl;
  for(map<char*, Room*>::iterator it = exits->begin(); it != exits->end(); ++it){
    cout << "Exit direction: " << it->first << " To room: " << it->second->name << endl;
  }
}

void Room::listItems(){
  for(vector<Item*>::iterator it = items->begin(); it != items->end(); ++it){
    cout << "Name: " << (*it)->getName() << endl;
  }
}

bool Room::removeItem(Item* item){
  for(vector<Item*>::iterator it = items->begin(); it != items->end(); ++it){
    if(!strcmp((*it)->getName(), item->getName())){
      delete *it;
      items->erase(it);
      return true;
    }else{
      return false;
    }
  }
  return true;
}

bool Room::addItem(Item* item){
  items->push_back(item);
  return true;
}

char* Room::getName(){
  return name;
}

vector<Item*>* Room::getItems(){
  return items;
}

map<char*, Room*>* Room::getExits(){
  return exits;
}
