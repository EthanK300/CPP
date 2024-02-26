#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;
/*
a: ethan k
shunting yard
operation and number parsing yay9ghapo4i3ehgpw4i3tu9q07tu-q2865uptqgggg
*/
//stack functions

void push(Node* &head, Node* node);
Node* pop(Node* &head);
Node* peek(Node* &head);

//queue functions

void enqueue(Node* &head, Node* node);
Node* dequeue(Node* &head);

int main(){
  Node* stackHead = NULL;
  Node* queueHead = NULL;
  char terminal[80];
  while(true){
    cout << "Enter expression:" << endl;
    cin.clear();
    cin >> terminal;
    for(int i = 0; i < strlen(terminal); i++){
      if(terminal[i] != '^' && !isdigit(terminal[i]) && terminal[i] != '+' && terminal[i] != '-' && terminal[i] != '*' && terminal[i] != '/' && terminal[i] != '(' && terminal[i] != ')'){
        memmove(terminal+i, terminal+1+i, strlen(terminal)-1-i);
	terminal[strlen(terminal)-1] = '\0';
        i--;
      }
    }
    //assume good inputs
    cout << "You have inputted: " << terminal << endl;
    for(int i = 0; i < strlen(terminal); i++){
      char c = terminal[i];
      Node* node = new Node(c);
      enqueue(stackHead, node);
    }
    //asssume character input translated to node links
  }
}

void push(Node* &head, Node* node){
  if(head == NULL){
    head = node;
  }else{
    Node* currentNode = head;
    while(currentNode != NULL){
      if(currentNode->getLeft() == NULL){
	currentNode->setLeft(node);
	return;
      }else{
	currentNode = currentNode->getLeft();
      }
    }
  }
}

Node* pop(Node* &head){
  if(head == NULL){
    cout << "Nothing to pop off!" << endl;
    return NULL;
  }else{
    Node* currentNode = head;
    while(currentNode != NULL){
      if(currentNode->getLeft() == NULL){
	return currentNode;
      }else{
	currentNode = currentNode->getLeft();
      }
    }
    return NULL;
  }
}

int peek(Node* &head, char c){
  Node* currentNode = head;
  while(currentNode != NULL){
    if(currentNode->getData() == c){
      return currentNode->getP();
    }else if(currentNode->getLeft() == NULL){
      cout << "No node to peek at with that value!" << endl;
      return -1;
    }else{
      currentNode = currentNode->getLeft();
    }
  }
  return -1;
}

void enqueue(Node* &head, Node* node){
  if(head == NULL){
    head = node;
  }else{
    Node* currentNode = head;
    while(currentNode != NULL){
      if(currentNode->getRight() == NULL){
	currentNode->setRight(node);
      }else{
	currentNode = currentNode->getRight();
      }
    }
  }
}

Node* dequeue(Node* &head){
  if(head == NULL){
    cout << "Q is empty!" << endl;
    return NULL;
  }else{
    Node* currentNode = head;
    Node* beforeNode = NULL;
    while(currentNode != NULL){
      if(currentNode->getRight() != NULL){
	beforeNode = currentNode;
	currentNode = currentNode->getRight();
      }else if(beforeNode == NULL){
	return currentNode;
      }else{
	Node* node = NULL;
	beforeNode->setRight(node);
	return currentNode;
      }
    }
    return NULL;
  }
}
