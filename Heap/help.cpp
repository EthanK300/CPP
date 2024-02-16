#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;

void ADD(int table[], int id, int end);
void DELETE(int table[], int &end);
void DISPLAYTREE(int table[], int index, int count, int end);
void FILL(int table[], int &end);

/*
Author: ethan k
heap

adds numbers in a tree form 
268435645ag684q346g5w15h36w54468i4e676o47865ollopu[uh\][;]-lp[pkl[0k1[`[0k[pklr

 */

int main(){
  int table[100];
  int end = 1;
  int i = 0;
  for(int p = 0; p < end + 100; p++){
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
      end++;
      ADD(table, id, end);
    }else if(!strcmp(terminal, "DISPLAYTREE")){
      cout << endl;
      DISPLAYTREE(table, 1, 0, end);
    }else if(!strcmp(terminal, "DELETE")){
      DELETE(table, end);
    }else if(!strcmp(terminal, "FILL")){
      FILL(table, end);
    }else if(!strcmp(terminal, "QUIT")){
      cout << "Quitted" << endl;
      return 0;
    }else{
      cout << "Bad Input" << endl;
    }
  }
}
//add number then resort tree
void ADD(int table[], int id, int end){
  int i = 1;
  for(i = 1; i < end; i++){
    if(table[i] == -1){
      table[i] = id;
      break;
    }
  }
  //check/reorganize table
  int ind = floor(i/2);
  while(table[i] > table[ind]){
    if(ind <= 0){
      return;
    }
    int child = table[i];
    int parent = table[ind];
    table[ind] = child;
    table[i] = parent;
    i = ind;
    ind = floor(i/2);
  }
}
//remove root, resort table
void DELETE(int table[], int &end){
  table[1] = table[end - 1];
  table[end - 1] = -1;
  end--;
  int i = 1;
  while((table[i] < table[(i * 2)+1] || table[i] < table[i * 2]) && i < end+1){
    if(table[i * 2] > table[(i * 2)+1]){
      int child = table[i];
      int parent = table[i * 2];
      table[i] = parent;
      table[i * 2] = child;
      i = i * 2;
    }else{
      int child = table[i];
      int parent = table[(i * 2)+1];
      table[i] = parent;
      table[(i * 2)+1] = child;
      i = i * 2 + 1;
    }
  }
}
//show tree in visual format
void DISPLAYTREE(int table[], int index, int count, int end){
  if((index * 2) + 1 < end){
    DISPLAYTREE(table, (index * 2) + 1, count + 1, end);
  }
  for(int a = 0; a < count; a++){
    cout << '\t';
  }
  cout << table[index] << endl;
  if((index * 2) < end){
    DISPLAYTREE(table, (index * 2), count + 1, end);
  }
}
//fill table from input data from file
void FILL(int table[], int &end){
  cout << "Adding students from file" << endl;
  ifstream nums;
  nums.open("numbers.txt");
  int inTable[100];
  char* input = new char[80];
  while(nums >> input){
    char* temp = new char[80];
    strcpy(temp, input);
    int n = atoi(temp);
    end++;
    ADD(table, n, end);
  }
}
