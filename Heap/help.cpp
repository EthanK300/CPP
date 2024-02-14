#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;

void ADD(int table[], int id, int end);
void DELETE(int table[], int end);
void DISPLAYTREE(int table[], int index, int count, int end);
void FILL(int table[]);

int main(){
  int table[100];
  int end = 100;
  for(int p = 0; p < end; p++){
    table[p] = -1;
  }
  char terminal[80];
  cout << "List of commands: ADD, DISPLAYTREE, DELETE, FILL, QUIT" << endl;
  while(true){
    cout << "Enter a command: " << endl;
    cin.clear();
    cin >> terminal;
    for(int i = 0; i < strlen(terminal); i++){
      if(!isalpha(terminal[i])){
	memmove(terminal+i, terminal+1+i, strlen(terminal)-i);
	i--;
      }
    }
    //assume good input
    if(!strcmp(terminal, "ADD")){
      cin.clear();
      cout << "Enter ID:" << endl;
      cin >> terminal;
      int id = atoi(terminal);
      ADD(table, id, end);
    }else if(!strcmp(terminal, "DISPLAYTREE")){
      DISPLAYTREE(table, 1, 0, end);
      end++;
    }else if(!strcmp(terminal, "DELETE")){
      DELETE(table, end);
    }else if(!strcmp(terminal, "FILL")){
      FILL(table);
    }else if(!strcmp(terminal, "QUIT")){
      cout << "Quitted" << endl;
      return 0;
    }else{
      cout << "Bad Input" << endl;
    }
  }
}

void ADD(int table[], int id, int end){
  int i = 0;
  for(i = 0; i < end; i++){
    if(table[i] == -1){
      table[i] = id;
      break;
    }
  }
  if(id == 30){
    cout << id << endl;
  }
  //check/reorganize table
  int ind = floor(i/2);
  while(table[i] > table[ind]){
    int child = table[i];
    int parent = table[ind];
    table[ind] = child;
    table[i] = parent;
    i = ind;
    ind = floor(i%2);
  }
}

void DELETE(int table[], int end){
  
}

void DISPLAYTREE(int table[], int index, int count, int end){
  if((index * 2) + 1 > end){
    DISPLAYTREE(table, (index * 2) + 1, count + 1, end);
  }
  for(int a = 0; a < count; a++){
    cout << '\t';
  }
  cout << table[index] << endl;
  if((index * 2) > end){
    DISPLAYTREE(table, (index * 2), count + 1, end);
  }
}

void FILL(int table[]){

}
