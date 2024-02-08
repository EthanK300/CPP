#include <iostream>
#include <cstring>
#include "Student.h"
#include "Node.h"
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

void ADD(Node** &INlist, int listLength, Node* node);
bool check(Node** &INlist, int listLength);
void DELETE(Node** &INlist, int listLength);
void PRINT(Node** &INlist, int listLength);
Node** rehash(Node** &INlist, int listLength);
int randomGenerate(Node** &INlist, int ListLength, int at);
/*
WHATTTTT AAAAAAA
w3o5ugbwql34ho82qh34tqnlgihsl39igt92qp34aligteh8oq3iag
*/

int main(){
  srand(time(NULL));
  //main running loop
  Node** init = new Node*[100];
  Node** workingList = init;
  bool active = true;
  int workingLength = 100;
  int at = 0;
  char terminal[80];
  cout << "List of commands: ADD, PRINT, DELETE, RANDOM, QUIT" << endl;
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
      node->setNext(NULL);
      ADD(workingList, workingLength, node);
    }else if(!strcmp(terminal, "PRINT")){
      PRINT(workingList, workingLength);
    }else if(!strcmp(terminal, "DELETE")){
      DELETE(workingList, workingLength);
    }else if(!strcmp(terminal, "RANDOM")){
      at = randomGenerate(workingList, workingLength, at);
    }else if(!strcmp(terminal, "QUIT")){
      cout << "Quitted" << endl;
      return 0;
    }else{
      cout << "Bad Input" << endl;
    }
    if(check(workingList, workingLength) == true){
      workingList = rehash(workingList, workingLength);
      workingLength = workingLength * 2;
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
  for(int j=0; j < listLength; j++){
    if(INlist[j] == NULL){
      continue;
    }else if(transfer == NULL){
      transfer = INlist[j];
    }else{
      newCurrentNode = transfer;
      while(newCurrentNode != NULL){
	if(newCurrentNode->getNext() != NULL){
	  newCurrentNode = newCurrentNode->getNext();
	}else{
	  newCurrentNode->setNext(INlist[j]);
	  break;
	}
      }
    }
  }
  //empty buffer into new list
  Node* nullNode = NULL;
  int z = 0;
  while(transfer != NULL){
    Student* student = new Student(z);
    student = transfer->getStudent();
    Node* outTransfer = new Node(student);
    outTransfer->setNext(nullNode);
    if(transfer != NULL){
      ADD(newList, newLength, outTransfer);
      transfer = transfer->getNext();
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

int randomGenerate(Node** &INlist, int listLength, int at){
  char terminal2[80];
  cout << "How many students to generate? Enter a number: " << endl;
  cin.clear();
  cin.ignore(10000, '\n');
  cin >> terminal2;
  int num = atoi(terminal2);
  ifstream firstNames;
  firstNames.open("firstnames.txt");
  ifstream lastNames;
  lastNames.open("lastnames.txt");
  char firstInput[80];
  char lastInput[80];
  vector<char*>* firstNameList = new vector<char*>();
  vector<char*>* lastNameList = new vector<char*>();

  while(firstNames >> firstInput){
    char* temp = new char[80];
    strcpy(temp, firstInput);
    firstNameList->push_back(temp);
  }
  while(lastNames >> lastInput){
    char* temp2 = new char[80];
    strcpy(temp2, lastInput);
    lastNameList->push_back(temp2);
  }
  char* frand;
  char* lrand;
  cout << rand() << endl;
  for(int i=0; i < num - 1; i++){
    int fr = rand() % (firstNameList->size());
    int lr = rand() % (lastNameList->size());
    cout << fr << "," << lr << "," << firstNameList->size() << "," << lastNameList->size() << endl;
    frand = firstNameList->at(fr);
    lrand = lastNameList->at(lr);
    char* t1 = new char[80];
    strcpy(t1, frand);
    char* t2 = new char[80];
    strcpy(t2, lrand);
    Student* student = new Student(t1, t2, at);
    at++;
    Node* node = new Node(student);
    node->setNext(NULL);
    ADD(INlist, listLength, node);
  }
  return at;
}
