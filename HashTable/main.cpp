#include <iostream>
#include <cstring>
#include "Student.h"
#include "Node.h"
#include <iomanip>

using namespace std;

void ADD(Node*[] list, int listLength, Node* node);
void DELETE(Node*[] list, int listLength);
void PRINT(Node*[] list, int listLength);
void randomGenerate();
/*
WHATTTTT AAAAAAA
w3o5ugbwql34ho82qh34tqnlgihsl39igt92qp34aligteh8oq3iag
*/
int main(){
  //main running loop
  int max = 3;
  Node* init = new Node[100];
  Node* workingList = init;
  Node* transfer = NULL;
  bool active = true;
  char terminal[80];
  cout << "List of commands: ADD, PRINT, DELETE, QUIT" << endl;
  while(int i=0; i < 100; i++){
    init[i] = NULL;
  }
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
    //assume good input
    Node* currentNode = head;
    if(!strcmp(terminal, "ADD")){
      Student* student = new Student();
      Node* node = new Node(student);
      ADD(workingList, workingList.length, node);
    }else if(!strcmp(terminal, "PRINT")){
      PRINT(workingList, workingList.length);
    }else if(!strcmp(terminal, "DELETE")){
      DELETE(workingList, workingList.length);
    }else if(!strcmp(terminal, "QUIT")){
      cout << "Quitted" << endl;
      return 0;
    }else{
      cout << "Bad Input" << endl;
    }
  }
}

//add nodes
void ADD(Node*[] list, int listLength, Node* node){
  int id = node->getStudent()->getStudentID();
  int sortID = id%%listLength;
  int break = 0;
  if(list[sortID] == NULL){
    list[sortID] = node;
  }else{
    Node currentNode = list[sortID];
    while(currentNode != NULL){
      if(currentNode->getNext() == NULL){
	list[sortID]->setNext(node);
      }else{
	currentNode = currentNode->getNext();
	break++;
      }
    }
  }
  if(break > max){
    
  }
}

//delete nodes, dynamically order list
void DELETE(Node*[] list, int listLength){
  int ID = 0;
  char terminal[80];
  cout << "Enter student ID: " << endl;
  cin.clear();
  cin >> terminal;
  ID = atoi(terminal);
  //TODO: find the right bucket, select, iterate through list and then
}
//search for student by id and print info
void PRINT(Node*[] list, int listLength){
  bool parseable = true;
  int ID = 0;
  char terminal[80];
  for(int i=0; i < listLength; i++){
    if(list[i]->getNext() == NULL){
      continue;
    }else{
      Node* currentNode = list[i]->getNext();
      while(currentNode != NULL){
	if(currentNode->getNext() == NULL){
	  break;
	}else{
	  currentNode->getStudent()->printInfo();
	  currentNode = currentNode->getNext();
	}
      }
    }
  }
}

void randomGenerate(){

}
