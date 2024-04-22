#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

/*
Author: Ethan K
graph creator eeeee
 */

void ADDV(vector<int>** matrix);
void ADDE(vector<int>** matrix);
void REMV(vector<int>** matrix);
void REME(vector<int>** matrix);
void FSP(vector<int>** matrix);

int main(){
  vector** matrix = new vector<vector<int>>();
  char terminal[80];
  cout << "Commands: ADDV, ADDE, REMV, REME, FSP, QUIT" << endl;
  while(true){
    cout << "Enter command:" << endl;
    cin.clear();
    cin >> terminal;
    for(int i = 0; i < strlen(terminal); i++){
      if(!isalpha(terminal[i])){  //if statement is the excludor
        memmove(terminal+i, terminal+1+i, strlen(terminal)-1-i);
	terminal[strlen(terminal)-1] = '\0';
        i--;
      }
    }
    //assume good inputs
    if(!strcmp(terminal, "ADDV")){
      
    }else if(!strcmp(terminal, "ADDE")){
      
    }else if(!strcmp(terminal, "REMV")){
      
    }else if(!strcmp(terminal, "REME")){
      
    }else if(!strcmp(terminal, "FSP")){
      
    }else if(!strcmp(terminal, "QUIT")){
      
    }else{
      cout << "Bad Input." << endl;
    }
  }
}

void ADDV(){
  
}

void ADDE(){

}

void REMV(){

}

void REME(){

}

void FSP(){

}
