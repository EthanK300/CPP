#include <iostream>
#include <cstring>
#include "Student.h"
#include "Node.h"
#include <iomanip>

using namespace std;

void ADD(Node** &INlist, int listLength, Node* node);
bool check(Node** &INlist, int listLength);
void DELETE(Node** &INlist, int listLength);
void PRINT(Node** &INlist, int listLength);
Node** rehash(Node** &INlist, int listLength);
void randomGenerate();
/*
WHATTTTT AAAAAAA
w3o5ugbwql34ho82qh34tqnlgihsl39igt92qp34aligteh8oq3iag
*/
int main(){
  //main running loop
  Node** init = new Node*[100];
  Node** workingList = init;
  bool active = true;
  int workingLength = 100;
  char terminal[80];
  cout << "List of commands: ADD, PRINT, DELETE, QUIT" << endl;
  for(int i=0; i < 100; i++){
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
    if(!strcmp(terminal, "ADD")){
      Student* student = new Student();
      Node* node = new Node(student);
      ADD(workingList, workingLength, node);
    }else if(!strcmp(terminal, "PRINT")){
      PRINT(workingList, workingLength);
    }else if(!strcmp(terminal, "DELETE")){
      DELETE(workingList, workingLength);
    }else if(!strcmp(terminal, "QUIT")){
      cout << "Quitted" << endl;
      return 0;
    }else{
      cout << "Bad Input" << endl;
    }
    if(check(workingList, workingLength) == true){
      workingList = rehash(workingList, workingLength);
    }
  }
}

//add nodes
void ADD(Node** &INlist, int listLength, Node* node){
  int id = node->getStudent()->getStudentID();
  int sortID = id%listLength;
  if(INlist[sortID] == NULL){
    INlist[sortID] = node;
  }else{
    Node* currentNode = INlist[sortID];
    while(currentNode != NULL){
      if(currentNode->getNext() == NULL){
	currentNode->setNext(node);
	return;
      }else{
	currentNode = currentNode->getNext();
      }
    }
  }
}

Node** rehash(Node** &INlist, int listLength){
  int newLength = listLength * 2;
  Node** newList = new Node*[newLength];
  for(int i=0; i < newLength; i++){
    newList[i] = NULL;
  }
  Node* transfer = NULL;
  Node* newCurrentNode = transfer;
  //empty original list into buffer
  for(int i=0; i < listLength; i++){
    if(INlist[i] == NULL){
      continue;
    }else if(transfer == NULL){
      transfer = INlist[i];
    }else{
      newCurrentNode = transfer;
      while(newCurrentNode != NULL){
	if(newCurrentNode->getNext() != NULL){
	  newCurrentNode = newCurrentNode->getNext();
	}else{
	  newCurrentNode->setNext(INlist[i]);
	}
      }
    }
  }
  //empty buffer into new list
  Node* nullNode = NULL;
  int z = 0;
  while(transfer->getNext() != NULL){
    Student* student = new Student(z);
    student = transfer->getStudent();
    Node* outTransfer = new Node(student);
    outTransfer->setNext(nullNode);
    if(transfer->getNext() != NULL){
      transfer = transfer->getNext();
      ADD(newList, newLength, outTransfer);
    }else{
      if(check(newList, newLength)){
	cout << "Rehash failed" << endl;
      }else{
	cout << "Rehash succeeded" << endl;
      }
      return newList;
    }
  }
  return newList;
}

bool check(Node** &INlist, int listLength){
  for(int i=0; i < listLength; i++){
    if(INlist[i] != NULL){
      if(INlist[i]->getNext() != NULL){
	if(INlist[i]->getNext()->getNext() != NULL){
	  if(INlist[i]->getNext()->getNext()->getNext() != NULL){
	    cout << "Check failed" << endl;
	    return true;
	  }
	}
      }
    } 
  }
  cout << "Check succeeded" << endl;
  return false;
}

//delete nodes, dynamically order list
void DELETE(Node** &INlist, int listLength){
  int ID = 0;
  char terminal[80];
  cout << "Enter student ID: " << endl;
  cin.clear();
  cin >> terminal;
  ID = atoi(terminal);
  //TODO: find the right bucket, select, iterate through list and then
}
//search for student by id and print info
void PRINT(Node** &INlist, int listLength){
  bool parseable = true;
  int ID = 0;
  char terminal[80];
  for(int i=0; i < listLength; i++){
    if(INlist[i] == NULL){
      continue;
    }else if(INlist[i]->getNext() == NULL){
      INlist[i]->getStudent()->printInfo();
    }else if(INlist[i]->getNext()->getNext() == NULL){
      INlist[i]->getStudent()->printInfo();
      INlist[i]->getNext()->getStudent()->printInfo();
    }else{
      INlist[i]->getStudent()->printInfo();
      INlist[i]->getNext()->getStudent()->printInfo();
      INlist[i]->getNext()->getNext()->getStudent()->printInfo();
    }
  }
}

void randomGenerate(){

}
