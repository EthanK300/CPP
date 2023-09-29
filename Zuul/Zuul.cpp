#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include "Item.h"

using namespace std;

int main(){
  bool active = true;
  char terminal[80];
  vector<Room*>* rooms = new vector<Room*>*();
  cout << "List of commands: ADD, SEARCH, DELETE, QUIT" << endl;
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
    if(!strcmp(terminal, "ADD")){
      ADD(database);
    }else if(!strcmp(terminal, "DELETE")){
      DELETE(database);
    }else if(!strcmp(terminal, "SEARCH")){
      SEARCH(database);
    }else if(!strcmp(terminal, "QUIT")){
      return 0;
    }else{
      cout << "Bad Input" << endl;
    }
  }
}
}
