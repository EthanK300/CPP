#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Room.h"

using namespace std;

Room::Room(char* nameIN){
  strcpy(name, nameIN);
}

bool Room::setExit(char* direction, Room* toRoom){
  exits->insert(pair<char*,Room*>(direction,toRoom));
  return true;
}

void Room::listExits(){
  for(map<char*, Room*>::iterator it = exits->begin(); it != exits->end(); ++it){
    cout << "Exit direction: " << it->first << " to room: " << it->second->name << endl;
  }
}

void Room::listItems(){
  for(vector<Item*>::iterator it = items->begin(); it != items->end(); ++it){
    cout << "Name: " << (*it)->getName() << endl;
  }
}

bool Room::removeItem(Item* item){
  for(vector<Item*>::iterator it = items->begin(); it != items->end(); ++it){
    if(strcmp((*it)->getName(), item->getName()) == 0){
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
