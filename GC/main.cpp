#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

/*
Author: Ethan K
graph creator eeeee
 */

void PRINT(int** matrix, int* vertices);
void ADDV(int** matrix, int* &vertices);
void ADDE(int** matrix, int* vertices);
void REMV(int** matrix, int* &vertices);
void REME(int** matrix, int* vertices);
void FSP(int** matrix, int* vertices);

int main(){
  int** matrix = new int*[20];
  int* vertices = new int[20];
  char terminal[80];
  for(int i = 0; i < 20 ; i++){
    matrix[i] = new int[20];
    vertices[i] = -1;
    //cout << endl;
    for(int j = 0; j < 20; j++){
      matrix[i][j] = -1;
      //cout << matrix[i][j] << "  ";
    }
  }
  cout << "Commands: PRINT, ADDV, ADDE, REMV, REME, FSP, QUIT" << endl;
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
      
    }else if(!strcmp(terminal, "PRINT")){
      PRINT(matrix);
    }else if(!strcmp(terminal, "QUIT")){
      return 0;
    }else{
      cout << "Bad Input." << endl;
    }
  }
}

void PRINT(int** matrix, int* vertices){
  cout << endl;
  for(int i = 0; i < 20 ; i++){
    cout << endl;
    for(int j = 0; j < 20; j++){
      cout << matrix[i][j] << "  ";
    }
    cout << endl;
  }
}

void ADDV(int** matrix, int* &vertices){
  
}

void ADDE(int** matrix, int* vertices){

}

void REMV(int** matrix, int* &vertices){

}

void REME(int** matrix, int* vertices){

}

void FSP(int** matrix, int* vertices){

}
