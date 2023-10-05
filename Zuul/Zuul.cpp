#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include "Item.h"

using namespace std;

bool move();
bool acquire();
bool drop();

int main(){
  bool active = true;
  char terminal[80];
  Room currentRoom = NULL;
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
      move();
    }else if(!strcmp(terminal, "ACQUIRE")){
      acquire();
    }else if(!strcmp(terminal, "DROP")){
      drop();
    }else if(!strcmp(terminal, "QUIT")){
      return 0;
    }else{
      cout << "Bad Input" << endl;
    }
  }
}

bool move(){
  
}

bool acquire(){

}

bool drop(){

}
