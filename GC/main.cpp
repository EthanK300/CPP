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
void ADDV(int* &vertices, int num);
void ADDE(int** &matrix, int* vertices, int weight, int first, int second);
void REMV(int** &matrix, int* &vertices, int num);
void REME(int** &matrix, int* vertices, int first, int second);
void FSP(int** matrix, int* vertices, int first, int second);

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
      cout << "enter number: " << endl;
      cin.clear();
      cin >> terminal;
      int num = atoi(terminal);
      ADDV(vertices, num);
    }else if(!strcmp(terminal, "ADDE")){
      cout << "enter weight: " << endl;
      cin.clear();
      cin >> terminal;
      int weight = atoi(terminal);
      cout << "enter 1st vertex (x): " << endl;
      cin.clear();
      cin >> terminal;
      int first = atoi(terminal);
      cout << "enter 2nd vertex (y): " << endl;
      cin.clear();
      cin >> terminal;
      int second = atoi(terminal);
      ADDE(matrix, vertices, first, second, weight);
    }else if(!strcmp(terminal, "REMV")){
      cout << "enter number: " << endl;
      cin.clear();
      cin >> terminal;
      int num = atoi(terminal);
      REMV(matrix, vertices, num);
    }else if(!strcmp(terminal, "REME")){
      cout << "enter 1st vertex (x): " << endl;
      cin.clear();
      cin >> terminal;
      int first = atoi(terminal);
      cout << "enter 2nd vertex (y): " << endl;
      cin.clear();
      cin >> terminal;
      int second = atoi(terminal);
      REME(matrix, vertices, first, second);
    }else if(!strcmp(terminal, "FSP")){
      cout << "enter 1st vertex: " << endl;
      cin.clear();
      cin >> terminal;
      int first = atoi(terminal);
      cout << "enter 2nd vertex: " << endl;
      cin.clear();
      cin >> terminal;
      int second = atoi(terminal);
      FSP(matrix, vertices, first, second);
    }else if(!strcmp(terminal, "PRINT")){
      PRINT(matrix, vertices);
    }else if(!strcmp(terminal, "QUIT")){
      return 0;
    }else{
      cout << "Bad Input." << endl;
    }
  }
}

void PRINT(int** matrix, int* vertices){
  cout << "Vertices:" << endl;
  for(int x = 0; x < 20; x++){
    cout << vertices[x] << "  ";
  }  
  cout << endl << "Adjacency Matrix:" << endl;
  for(int i = 0; i < 20 ; i++){
    cout << endl;
    for(int j = 0; j < 20; j++){
      cout << matrix[i][j] << "  ";
    }
    cout << endl;
  }
}

void ADDV(int* &vertices, int num){
  for(int i = 0; i < 20 + 1; i++){
    if(vertices[i] == -1){
      vertices[i] = num;
      return;
    }
  }
  cout << "Maximum number of vertices reached" << endl;
}

void ADDE(int** &matrix, int* vertices, int first, int second, int weight){
  int fi = -1;
  int si = -1;
  for(int i = 0; i < 20; i++){
    if(vertices[i] == first){
      fi = i;
    }
    if(vertices[i] == second){
      si = i;
    }
  }
  if(fi == -1 || si == -1){
    cout << "One of the vertices does not exist" << endl;
  }else{
    matrix[si][fi] = weight;
  }
}

void REMV(int** &matrix, int* &vertices, int num){
  for(int i = 0; i < 20; i++){
    if(vertices[i] == num){
      vertices[i] = -1;
      for(int j = 0; j < 20; j++){
        matrix[j][i] = -1;
      }
      return;
    }
  }
  cout << "Vertice not in matrix!" << endl;
}

void REME(int** &matrix, int* vertices, int first, int second){
  int x = -1;
  int y = -1;
  for(int i = 0; i < 20; i++){
    if(vertices[i] == first){
      x = i;
    }
  }
  for(int i = 0; i < 20; i++){
    if(vertices[i] == second){
      y = i;
    }
  }
  if(x == -1 || y == -1){
    cout << "One of the vertices does not exist!" << endl;
  }
  if(matrix[y][x] != -1){
    matrix[y][x] = -1;
  }else{
    cout << "No edge between those vertices!" << endl;
  }
}

void FSP(int** matrix, int* vertices, int first, int second){
  
}
