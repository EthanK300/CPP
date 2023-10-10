#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include "Item.h"

using namespace std;

bool move(Room* currentRoom, vector<Item*>* inventory);
bool acquire(Room* currentRoom, vector<Item*>* inventory);
bool drop(Room* currentRoom, vector<Item*>* inventory);
bool loadResources(Room* currentRoom);

int main(){
  bool active = true;
  char terminal[80];
  Room* currentRoom = NULL;
  vector<Room*>* rooms = new vector<Room*>();
  vector<Item*>* inventory = new vector<Item*>();
  cout << "List of commands: MOVE, ACQUIRE, DROP, QUIT" << endl;
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
      move(currentRoom, inventory);
    }else if(!strcmp(terminal, "ACQUIRE")){
      acquire(currentRoom, inventory);
    }else if(!strcmp(terminal, "DROP")){
      drop(currentRoom, inventory);
    }else if(!strcmp(terminal, "QUIT")){
      return 0;
    }else{
      cout << "Bad Input" << endl;
    }
  }
}

bool move(Room* currentRoom, vector<Item*>* inventory){
  
}

bool acquire(Room* currentRoom, vector<Item*>* inventory){
  bool valid = true;
  char terminal[80];
  cout << "Items in room: " << endl;
  for(vector<Item*>::iterator it = currentRoom->getItems()->begin(); it != currentRoom->getItems()->end(); ++it){
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
    for(vector<Item*>::iterator it = currentRoom->getItems()->begin(); it != currentRoom->getItems()->end(); ++it){
      if(!strcmp((*it)->getName(), terminal)){
	valid = false;
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
}

bool loadResources(){
  
}
