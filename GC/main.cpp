#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;

/*
Author: Ethan K
graph creator eeeee
 */

class Node{
public:
  Node(int a){
    data = a;
    next = NULL;
  }

  void setNext(Node* node){
    next = node;
  }

  Node* getNext(){
    return next;
  }

  int getData(){
    return data;
  }
  
protected:
  int data;
  int dist;
  Node* next;
};

void PRINT(int** matrix, int* vertices);
void ADDV(int* &vertices, int num);
void ADDE(int** &matrix, int* vertices, int weight, int first, int second);
void REMV(int** &matrix, int* &vertices, int num);
void REME(int** &matrix, int* vertices, int first, int second);
void FSP(int** matrix, int* vertices, int first, int second);
int find(int* vertices, int value);

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
  int fi = find(vertices, first);
  int si = find(vertices, second);
  if(fi == -1 || si == -1){
    cout << "One of the vertices does not exist" << endl;
  }else{
    matrix[fi][si] = weight;
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
  int x = find(vertices, first);
  int y = find(vertices, second);
  if(x == -1 || y == -1){
    cout << "One of the vertices does not exist!" << endl;
  }
  if(matrix[y][x] != -1){
    matrix[y][x] = -1;
  }else{
    cout << "No edge between those vertices!" << endl;
  }
}

int find(int* vertices, int value){
  for(int i = 0; i < 20; i++){
    if(vertices[i] == value){
      return i;
    }
  }
  return -1;
}

int small(int* distances, int* unvisited, int* vertices){
  int min = INT_MAX;
  for(int i = 0; i < 20; i++){
    if(unvisited[i] != -1){
      int o = find(vertices, unvisited[i]);
      cout << "vertice: " << vertices[o] << endl;
      if(distances[o] < min){
	min = distances[o];
      }
    }
  }
  if(min == INT_MAX){
    return -1;
  }else{
    return find(distances, min);
  }
}

int* trace(int** matrix, int* vertices, int num, int* accessible){
  int i = find(vertices, num);
  for(int j = 0; j < 20; j++){
    if(matrix[i][j] != -1 && (find(accessible, vertices[j]) == -1)){
      for(int k = 0; k < 20; k++){
	if(accessible[k] == -1){
	  accessible[k] = vertices[j];
	  accessible = trace(matrix, vertices, vertices[j], accessible);
	  break;
	}
      }
    }
  }
  return accessible;
}

int* unvisit(int** matrix, int* vertices, int first, int second){
  bool fh = false;
  bool sh = false;
  for(int i = 0; i < 20; i++){
    if(vertices[i] == fh && vertices[i] == sh){
      cout << "Distance to the same point is 0!" << endl;
      return NULL;
    }else if(vertices[i] == fh){
      fh = true;
    }else if(vertices[i] == sh){
      sh = true;
    }
  }
  int* unvisited = new int[20];
  for(int i = 0; i < 20; i++){
    unvisited[i] = -1;
  }
  unvisited[0] = first;
  unvisited = trace(matrix, vertices, first, unvisited);
  return unvisited;
}

void FSP(int** matrix, int* vertices, int first, int second){
  if(find(vertices, first) == -1 || find(vertices, second) == -1){
    cout << "Can't find distance to nothing!" << endl;
    return;
  }
  int* unvisited = unvisit(matrix, vertices, first, second);
  if(unvisited == NULL){
    return;
  }
  for(int h = 0; h < 20; h++){
    cout << unvisited[h] << "  ";
  }
  cout << endl;
  Node** previous = new Node*[20];
  bool active = true;
  bool on = true;
  for(int i = 0; i < 20; i++){
    Node* node = new Node(vertices[i]);
    previous[i] = node;
  }
  int* visited = new int[20];
  int* dist = new int[20];
  for(int i = 0; i < 20; i++){
    dist[i] = INT_MAX;
    visited[i] = -1;
  }
  dist[find(vertices, first)] = 0;
  int lv = 0;
  while(active && on){
    int cvi = small(dist, unvisited, vertices);
    int cv = vertices[cvi];
    if(lv == 0){
      lv = cv;
    }else if(cv == lv){
      cout << "No path found!" << endl;
      return;
    }
    cout << "index: " << cvi << " vertice: " << cv << endl;
    cout << "working on vertex: " << cv << endl;
    for(int i = 0; i < 20; i++){
      if(matrix[cvi][i] == -1){
	cout << "skipped " << cvi << "," << i << " with edge " << matrix[cvi][i] << endl;
	continue;
      }else{
	cout << "working on edge between " << cv << " and " << vertices[i] << ", with current distance " << dist[i] << " and comparing distance " << dist[cvi] + matrix[cvi][i] << endl;
	if(dist[i] > (dist[cvi] + matrix[cvi][i])){
	  dist[i] = dist[cvi] + matrix[cvi][i];
	  previous[i]->setNext(previous[cvi]);
	  cout << "found smaller path for " << cv << " and " << vertices[i] << ", setting " << vertices[i] << "'s previous to " << vertices[cvi] << endl;
	}
      }
    }
    cout << "here" << endl;
    active = false;
    for(int j = 0; j < 20; j++){
      if(visited[j] == -1){
	visited[j] = cv;
	unvisited[cvi] = -1;
	j == 19 ? active = false : active = true;
	break;
      }
    }
    on = false;
    for(int k = 0; k < 20; k++){
      if(unvisited[k] != -1){
	on = true;
      }
    }
  }
  Node* currentNode = previous[find(vertices, second)];
  cout << "shortest path is through: " << endl;
  while(currentNode != NULL){
    cout << "Vertice " << currentNode->getData() << "," << endl;
    currentNode = currentNode->getNext();
  }
}
