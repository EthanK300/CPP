#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

/*
Author: Ethan K
graph creator eeeee
 */

void PRINT(int** matrix);
void ADDV(int* &vertices, int num, int vLength);
void ADDE(int** &matrix, int* vertices, int vLength, int weight, int first, int second);
void REMV(int** &matrix, int* &vertices, int num, int vLength);
void REME(int** &matrix, int* vertices, int vLength, int weight);
void FSP(int** matrix, int* vertices, int vLength, int first, int second);

int main(){
  int** matrix = new int*[20];
  int* vertices = new int[20];
  int vLength = 0;
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
      ADDV(vertices, num, vLength);
      vLength++;
    }else if(!strcmp(terminal, "ADDE")){
      cout << "enter weight: " << endl;
      cin.clear();
      cin >> terminal;
      int weight = atoi(terminal);
      cout << "enter 1st vertex: " << endl;
      cin.clear();
      cin >> terminal;
      int first = atoi(terminal);
      cout << "enter 2nd vertex: " << endl;
      cin.clear();
      cin >> terminal;
      int second = atoi(terminal);
      ADDE(matrix, vertices, vLength, first, second, weight);
    }else if(!strcmp(terminal, "REMV")){
      cout << "enter number: " << endl;
      cin.clear();
      cin >> terminal;
      int num = atoi(terminal);
      REMV(matrix, vertices, vLength, num);
      vLength--;
    }else if(!strcmp(terminal, "REME")){
      cout << "enter weight: " << endl;
      cin.clear();
      cin >> terminal;
      int weight = atoi(terminal);
      REME(matrix, vertices, vLength, weight);
    }else if(!strcmp(terminal, "FSP")){
      cout << "enter 1st vertex: " << endl;
      cin.clear();
      cin >> terminal;
      int first = atoi(terminal);
      cout << "enter 2nd vertex: " << endl;
      cin.clear();
      cin >> terminal;
      int second = atoi(terminal);
      FSP(matrix, vertices, vLength, first, second);
    }else if(!strcmp(terminal, "PRINT")){
      PRINT(matrix);
    }else if(!strcmp(terminal, "QUIT")){
      return 0;
    }else{
      cout << "Bad Input." << endl;
    }
  }
}

void PRINT(int** matrix){
  cout << endl;
  for(int i = 0; i < 20 ; i++){
    cout << endl;
    for(int j = 0; j < 20; j++){
      cout << matrix[i][j] << "  ";
    }
    cout << endl;
  }
}

void ADDV(int* &vertices, int num, int vLength){
  cout << num << "." << vLength << endl;
  for(int i = 0; i < vLength + 1; i++){
    if(vertices[i] == -1){
      vertices[i] = num;
      break;
    }
  }
}

void ADDE(int** &matrix, int* vertices, int vLength, int first, int second, int weight){

}

void REMV(int** &matrix, int* &vertices, int vLength, int num){

}

void REME(int** &matrix, int* vertices, int vLength, int weight){

}

void FSP(int** matrix, int* vertices, int vLength, int first, int second){

}
