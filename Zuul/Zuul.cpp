#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include "Item.h"

using namespace std;

bool move(Room* currentRoom);
bool acquire(Room* currentRoom, vector<Item*>* inventory);
bool listInventory(vector<Item*>* inventory);
bool drop(Room* currentRoom, vector<Item*>* inventory);
bool loadResources(vector<Room*>* rooms, Room* &currentRoom);
bool openMap(vector<Room*>* listRooms);

int main(){
  bool active = true;
  char terminal[80];
  Room* currentRoom = NULL;
  vector<Room*>* rooms = new vector<Room*>();
  vector<Item*>* inventory = new vector<Item*>();
  if(!loadResources(rooms, currentRoom)){
    cout << "Failed to load resources." << endl;
    return 1;
  }
  cout << "List of commands: MOVE, MAP, ACQUIRE, DROP, INV, QUIT" << endl;
  while(active){
    cout << "Enter a command: " << endl;
    cin.clear();
    cin >> terminal;
    for(int i = 0; i < strlen(terminal); i++){
      if(!isalpha(terminal[i])){
	memmove(terminal+i, terminal+1+i, strlen(terminal)-i);
	i--;
      }
    }
    //good command string
    if(!strcmp(terminal, "MOVE")){
      move(currentRoom);
    }else if(!strcmp(terminal, "ACQUIRE")){
      acquire(currentRoom, inventory);
    }else if(!strcmp(terminal, "DROP")){
      drop(currentRoom, inventory);
    }else if(!strcmp(terminal, "MAP")){
      openMap(rooms);
    }else if(!strcmp(terminal, "INV")){
      listInventory(inventory);
    }else if(!strcmp(terminal, "QUIT")){
      return 0;
    }else{
      cout << "Bad Input" << endl;
    }
  }
  return 0;
}
bool openMap(vector<Room*>* roomsIN){
  for(vector<Room*>::iterator it = roomsIN->begin(); it != roomsIN->end(); ++it){
    cout << "Room " << (*it)->getName() << " exits to: " << endl;
    (*it)->listExits();
    cout << endl;
  }
  return true;
}

bool move(Room* currentRoom){
  bool valid = true;
  char terminal[80];
  currentRoom->listExits();
  while(valid){
    cout << "Where to?" << endl;
    cin.clear();
    cin >> terminal;
    for(int i = 0; i < strlen(terminal); i++){
      if(!isalpha(terminal[i])){
	memmove(terminal+i, terminal+1+i, strlen(terminal)-i);
	i--;
      }
    }
    map<char*, Room*>* currentExitMap = currentRoom->getExits();
    for(map<char*, Room*>::iterator it = currentExitMap->begin(); it != currentExitMap->end(); ++it){
      if(!strcmp(terminal,(it)->first)){
	currentRoom = (it)->second;
	valid = false;
	return true;
      }
    }
    if(!strcmp(terminal, "QUIT")){
      cout << "Didn't move anywhere." << endl;
      valid = true;
      return true;
    }
  }
  return false;
}

bool acquire(Room* currentRoom, vector<Item*>* inventory){
  bool valid = true;
  char terminal[80];
  cout << "Items in room: " << endl;
  currentRoom->listItems();
  while(valid){
    cin.clear();
    cin >> terminal;
    cin.ignore(10000, '\n');
    for(int i = 0; i < strlen(terminal); i++){
      if(!isalpha(terminal[i])){
	memmove(terminal+i, terminal+1+i, strlen(terminal)-i);
	i--;
      }
    }
    for(vector<Item*>::iterator it = currentRoom->getItems()->begin(); it != currentRoom->getItems()->end(); ++it){
      if(!strcmp((*it)->getName(), terminal)){
	valid = false;
	cout << "Picked up " << (*it)->getName() << endl;
	inventory->push_back(*it);
	currentRoom->removeItem(*it);        
	return true;
      }
    }
    if(!strcmp(terminal, "NONE")){
      cout << "Didn't pick up anything" << endl;
      valid = false;
      return true;
    }else{
      valid = true;
    }
    cout << "Bad Input." << endl;
  }
  return false;
}

bool listInventory(vector<Item*>* inventory){
  cout << "Items in inventory: " << endl;
  for(vector<Item*>::iterator it = inventory->begin(); it != inventory->end(); ++it){
    cout << (*it)->getName() << endl;
  }
  return true;
}

bool drop(Room* currentRoom, vector<Item*>* inventory){
  bool valid = true;
  char terminal[80];
  cout << "What would you like to drop? Select an item or enter NONE" << endl << "Inventory: " << endl;
  for(vector<Item*>::iterator it = inventory->begin(); it != inventory->end(); ++it){
    cout << (*it)->getName() << endl;
  }
  while(valid){
    cin.clear();
    cin >> terminal;
    cin.ignore(10000, '\n');
    for(int i = 0; i < strlen(terminal); i++){
      if(!isalpha(terminal[i])){
	memmove(terminal+i, terminal+1+i, strlen(terminal)-i);
	i--;
      }
    }
    for(vector<Item*>::iterator it = inventory->begin(); it != inventory->end(); ++it){
      if(!strcmp((*it)->getName(), terminal)){
	valid = false;
	cout << "Dropped " << (*it)->getName() << " in " << currentRoom->getName() << endl;
	currentRoom->addItem((*it));
	inventory->erase(it);
	return true;
      }
    }
    if(!strcmp(terminal, "NONE")){
      cout << "Didn't drop anything" << endl;
      valid = false;
      return true;
    }else{
      valid = true;
    }
    cout << "Bad Input." << endl;
  }
  return false;
}

bool loadResources(vector<Room*>* rooms, Room* &currentRoom){
  char* name = new char[80];
  char* exit = new char[80];
  
  //create items
  strcpy(name, "note");
  Item* note = new Item(name);
  strcpy(name, "fuel");
  Item* fuel = new Item(name);
  strcpy(name, "energycells");
  Item* energycells = new Item(name);
  strcpy(name, "controlchip");
  Item* controlchip = new Item(name);
  strcpy(name, "toolbox");
  Item* toolbox = new Item(name);
  
  //create rooms
  strcpy(name, "earth");
  Room* earth = new Room(name);
  strcpy(name, "outer space");
  Room* space = new Room(name);
  strcpy(name, "spaceship");
  Room* spaceship = new Room(name);
  strcpy(name, "moon");
  Room* moon = new Room(name);
  
  //set exits
  strcpy(exit, "rocket_pad");
  earth->setExit(exit, spaceship);
  spaceship->setExit(exit, earth);
  strcpy(exit, "fly to: moon landing port");
  spaceship->setExit(exit, moon);
  strcpy(exit, "landing port");
  moon->setExit(exit, spaceship);

  //add items to rooms
  earth->addItem(fuel);
  earth->addItem(note);
  earth->addItem(energycells);
  moon->addItem(controlchip);
  spaceship->addItem(toolbox);
  
  //add rooms to operatable list
  rooms->push_back(moon);
  rooms->push_back(earth);
  rooms->push_back(spaceship);
  
  currentRoom = earth;
  return true;
}
