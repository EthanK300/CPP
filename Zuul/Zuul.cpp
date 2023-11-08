#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include "Item.h"

using namespace std;

//Author: Ethan K, zuul project but space themed...

bool loadResources(vector<Room*>* &rooms, Room* &currentRoom);
bool move(Room* &currentRoom);
bool acquire(Room* &currentRoom, vector<Item*>* &inventory);
bool listInventory(vector<Item*>* &inventory);
bool drop(Room* &currentRoom, vector<Item*>* &inventory);
bool openMap(vector<Room*>* &listRooms);
void checkIfWon(Room* &currentRoom, vector<Item*>* &inventory, vector<Room*>* &rooms);
bool contains(vector<Room*>* &rooms, char* roomName, char* name);
bool contains(vector<Item*>* &inventory, char* name);

//main running loop
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
  cout << "MOVE COMMAND SYNTAX: when moving from spaceship->anywhere, fly to: place, when moving from anywhere->anywhere, place" << endl;
  while(active){
    checkIfWon(currentRoom, inventory, rooms);
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
//prints out connections of rooms
bool openMap(vector<Room*>* &roomsIN){
  for(vector<Room*>::iterator it = roomsIN->begin(); it != roomsIN->end(); ++it){
    cout << (*it)->getName() << " exits to: " << endl;
    (*it)->listExits();
    cout << endl;
  }
  return true;
}
//check winning conditions, runs each time after commands
void checkIfWon(Room* &currentRoom, vector<Item*>* &inventory, vector<Room*>* &rooms){
  char* winRoom = new char[80];
  strcpy(winRoom, "spaceship");
  if(strcmp(currentRoom->getName(), winRoom) == 0){
    char* bubbleTeaT = new char[80];
    strcpy(bubbleTeaT, "bubbletea");
    char* fuelT = new char[80];
    strcpy(fuelT, "fuel");
    char* spaceshipT = new char[80];
    strcpy(spaceshipT, "spaceship");
    if(contains(inventory, bubbleTeaT) && contains(rooms, spaceshipT, fuelT)){
      //win!
      cout << "You Won!" << endl;
      exit(0);
      return;
    }
  }
  return;
}
//helper function for check win
bool contains(vector<Room*>* &rooms, char* roomName, char* name){
  for(vector<Room*>::iterator it = rooms->begin(); it != rooms->end(); ++it){
    if(strcmp((*it)->getName(), roomName) == 0){
      for(vector<Item*>::iterator it2 = (*it)->getItems()->begin(); it2 != (*it)->getItems()->end(); ++it2){
	if(strcmp((*it2)->getName(), name) == 0){
	  return true;
	}
      }
    }
  }
  return false;
}
//overloaded helper function
bool contains(vector<Item*>* &inventory, char*name){
  for(vector<Item*>::iterator it = inventory->begin(); it != inventory->end(); ++it){
    if(strcmp((*it)->getName(), name) == 0){
      return true;
    }
  }
  return false;
}
//move somewhere
bool move(Room* &currentRoom){
  bool valid = true;
  char terminal[80];
  currentRoom->listExits();
  cin.get();
  while(valid){
    cout << "Where to?" << endl;
    cin.clear();
    cin.getline(terminal, 80);
    for(int i = 0; i < strlen(terminal); i++){
      if(!isalpha(terminal[i]) && !(terminal[i] == ' ') && !(terminal[i] == ':')){
	memmove(terminal+i, terminal+1+i, strlen(terminal)-i);
	i--;
      }
    }
    map<char*, Room*>* currentExitMap = currentRoom->getExits();
    for(map<char*, Room*>::iterator it = currentExitMap->begin(); it != currentExitMap->end(); ++it){
      if(!strcmp(terminal,(it)->first)){
	currentRoom = (it)->second;
	valid = false;
	cout << "In " << currentRoom->getName() << endl;
	return true;
      }
    }
    if(!strcmp(terminal, "QUIT")){
      cout << "Didn't move anywhere." << endl;
      valid = true;
      return true;
    }
    cout << "Bad input." << endl;
  }
  return false;
}
//pick up something
bool acquire(Room* &currentRoom, vector<Item*>* &inventory){
  bool valid = true;
  char terminal[80];
  cout << "Items in room: " << endl;
  currentRoom->listItems();
  cin.get();
  while(valid){
    cout << "What to acquire?" << endl;
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
//list out inventory items
bool listInventory(vector<Item*>* &inventory){
  cout << "Items in inventory: " << endl;
  for(vector<Item*>::iterator it = inventory->begin(); it != inventory->end(); ++it){
    cout << (*it)->getName() << endl;
  }
  return true;
}
//drop item in current room
bool drop(Room* &currentRoom, vector<Item*>* &inventory){
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
//load everything
bool loadResources(vector<Room*>* &rooms, Room* &currentRoom){
  //create items
  char* note1 = new char[80];
  strcpy(note1, "note");
  Item* note = new Item(note1);
  
  char* fuel1 = new char[80];
  strcpy(fuel1, "fuel");
  Item* fuel = new Item(fuel1);

  char* energycells1 = new char[80];
  strcpy(energycells1, "energycells");
  Item* energycells = new Item(energycells1);

  char* controlchip1 = new char[80];
  strcpy(controlchip1, "controlchip");
  Item* controlchip = new Item(controlchip1);
  
  char* toolbox1 = new char[80];
  strcpy(toolbox1, "toolbox");
  Item* toolbox = new Item(toolbox1);

  char* passenger1 = new char[80];
  strcpy(passenger1, "passenger");
  Item* passenger = new Item(passenger1);

  char* bubbletea1 = new char[80];
  strcpy(bubbletea1, "bubbletea");
  Item* bubbletea = new Item(bubbletea1);

  char* tiramisu1 = new char[80];
  strcpy(tiramisu1, "tiramisu");
  Item* tiramisu = new Item(tiramisu1);
  
  //create rooms
  char* earth1 = new char[80];
  strcpy(earth1, "earth");
  Room* earth = new Room(earth1);
  
  char* outerspace1 = new char[80];
  strcpy(outerspace1, "outer space");
  Room* space = new Room(outerspace1);

  char* spaceship1 = new char[80];
  strcpy(spaceship1, "spaceship");
  Room* spaceship = new Room(spaceship1);

  char* moon1 = new char[80];
  strcpy(moon1, "moon");
  Room* moon = new Room(moon1);

  char* theSun1 = new char[80];
  strcpy(theSun1, "the sun");
  Room* theSun = new Room(theSun1);

  char* tradeHub1 = new char[80];
  strcpy(tradeHub1, "interstellar trade hub");
  Room* tradeHub = new Room(tradeHub1);

  char* moonStation1 = new char[80];
  strcpy(moonStation1, "moon mining station");
  Room* moonStation = new Room(moonStation1);

  char* refinery1 = new char[80];
  strcpy(refinery1, "refinery");
  Room* refinery = new Room(refinery1);

  char* recyclingplant1 = new char[80];
  strcpy(recyclingplant1, "recycling plant");
  Room* recyclingplant = new Room(recyclingplant1);

  char* warpgate1 = new char[80];
  strcpy(warpgate1, "warp gate");
  Room* warpgate = new Room(warpgate1);

  char* cosmicanomaly1 = new char[80];
  strcpy(cosmicanomaly1, "cosmic anomaly");
  Room* cosmicanomaly = new Room(cosmicanomaly1);

  char* shipwreck1 = new char[80];
  strcpy(shipwreck1, "shipwreck");
  Room* shipwreck = new Room(shipwreck1);

  char* timewarpportal1 = new char[80];
  strcpy(timewarpportal1, "time warp portal");
  Room* timewarpportal = new Room(timewarpportal1);

  char* weaponsplant1 = new char[80];
  strcpy(weaponsplant1, "weapons plant");
  Room* weaponsplant = new Room(weaponsplant1);

  char* spacefortress1 = new char[80];
  strcpy(spacefortress1, "space fortress");
  Room* spacefortress = new Room(spacefortress1);

  char* blackhole1 = new char[80];
  strcpy(blackhole1, "black hole");
  Room* blackhole = new Room(blackhole1);

  char* wormhole1 = new char[80];
  strcpy(wormhole1, "worm hole");
  Room* wormhole = new Room(wormhole1);

  
  //set exits

  char* flyWH = new char[80];
  strcpy(flyWH, "fly to: wormhole entrance");
  spaceship->setExit(flyWH, wormhole);

  char* whout = new char[80];
  strcpy(whout, "landing port");
  wormhole->setExit(whout, spaceship);
  
  char* flyBH = new char[80];
  strcpy(flyBH, "fly to: black hole entrance");
  spaceship->setExit(flyBH, blackhole);

  char* bhout = new char[80];
  strcpy(bhout, "landing port");
  blackhole->setExit(bhout, spaceship);
  
  char* flySF = new char[80];
  strcpy(flySF, "fly to: force field of space fortress");
  spaceship->setExit(flySF, spacefortress);

  char* sfout = new char[80];
  strcpy(sfout, "landing port");
  spacefortress->setExit(sfout, spaceship);

  char* ssout = new char[80];
  strcpy(ssout, "death");
  theSun->setExit(ssout, theSun);
  
  char* flyWP = new char[80];
  strcpy(flyWP, "fly to: weapons plant");
  spaceship->setExit(flyWP, weaponsplant);

  char* wpout = new char[80];
  strcpy(wpout, "landing port");
  weaponsplant->setExit(wpout, spaceship);
  
  char* flyTWP = new char[80];
  strcpy(flyTWP, "fly to: time warp portal");
  spaceship->setExit(flyTWP, timewarpportal);

  char* twpout = new char[80];
  strcpy(twpout, "landing port");
  timewarpportal->setExit(twpout, spaceship);

  char* flySR = new char[80];
  strcpy(flySR, "fly to: shipwreck");
  spaceship->setExit(flySR, shipwreck);
  
  char* rocketpad1 = new char[80];
  strcpy(rocketpad1, "fly to: rocket pad");
  earth->setExit(rocketpad1, spaceship);
  spaceship->setExit(rocketpad1, earth);

  char* flyMLP = new char[80];
  strcpy(flyMLP, "fly to: moon landing port");
  spaceship->setExit(flyMLP, moon);

  char* lp1 = new char[80];
  strcpy(lp1, "landing port");
  moon->setExit(lp1, spaceship);

  char* flyTS = new char[80];
  strcpy(flyTS, "fly to: the sun");
  spaceship->setExit(flyTS, theSun);
  
  char* flyTH = new char[80];
  strcpy(flyTH, "fly to: trade hub");
  spaceship->setExit(flyTH, tradeHub);

  char* flyR = new char[80];
  strcpy(flyR, "fly to: refinery");
  spaceship->setExit(flyR, refinery);

  char* flyRP = new char[80];
  strcpy(flyRP, "fly to: recyclingplant");
  spaceship->setExit(flyRP, recyclingplant);

  char* flyWG = new char[80];
  strcpy(flyWG, "fly to: landing port");
  spaceship->setExit(flyWG, warpgate);

  char* flyCA = new char[80];
  strcpy(flyCA, "fly to: gaseous cloud");
  spaceship->setExit(flyCA, cosmicanomaly);
  
  char* lp2 = new char[80];
  strcpy(lp2, "landing port");
  tradeHub->setExit(lp2, spaceship);

  char* flyMMS = new char[80];
  strcpy(flyMMS, "fly to: moon mining station");
  spaceship->setExit(flyMMS, moonStation);

  char* lp3 = new char[80];
  strcpy(lp3, "landing port");
  moonStation->setExit(lp3, spaceship);

  char* lp4 = new char[80];
  strcpy(lp4, "landing port");
  refinery->setExit(lp4, spaceship);

  char* lp5 = new char[80];
  strcpy(lp5, "landing port");
  recyclingplant->setExit(lp5, spaceship);

  char* lp6 = new char[80];
  strcpy(lp6, "landing port");
  warpgate->setExit(lp6, spaceship);

  char* lp7 = new char[80];
  strcpy(lp7, "gaseous cloud");
  cosmicanomaly->setExit(lp7, spaceship);

  char* lp8 = new char[80];
  strcpy(lp8, "battleground");
  shipwreck->setExit(lp8, spaceship);
  
  //add items to rooms
  earth->addItem(fuel);
  earth->addItem(note);
  earth->addItem(energycells);
  moon->addItem(controlchip);
  spaceship->addItem(toolbox);
  tradeHub->addItem(bubbletea);
  tradeHub->addItem(tiramisu);
  
  //add rooms to operatable list
  rooms->push_back(recyclingplant);
  rooms->push_back(warpgate);
  rooms->push_back(refinery);
  rooms->push_back(cosmicanomaly);
  rooms->push_back(moon);
  rooms->push_back(earth);
  rooms->push_back(theSun);
  rooms->push_back(tradeHub);
  rooms->push_back(moonStation);
  rooms->push_back(blackhole);
  rooms->push_back(shipwreck);
  rooms->push_back(timewarpportal);
  rooms->push_back(spacefortress);
  rooms->push_back(weaponsplant);
  rooms->push_back(wormhole);
  rooms->push_back(spaceship);
  
  currentRoom = earth;
  return true;
}
