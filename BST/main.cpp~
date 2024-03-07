#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;
/*
a: ethan k
shunting yard
operation and number parsing yay9ghapo4i3ehgpw4i3tu9q07tu-q2865uptqgggg
*/

//print functions

void infix(Node* treeHead);
void prefix(Node* treeHead);
void postfix(Node* treeHead);

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
  Node* outQueueHead = NULL;
  Node* treeStackHead = NULL;
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
      if(node->getData() == ')' || node->getData() == '('){
	node->setP(5);
      }else if(node->getData() == '^'){
	node->setP(4);
      }else if(node->getData() == '*' || node->getData() == '/'){
	node->setP(3);
      }else if(node->getData() == '+' || node->getData() == '-'){
	node->setP(2);
      }else{
	node->setP(1);
      }
      enqueue(queueHead, node);
    }
    //asssume character input translated to node links
    while(queueHead != NULL){
      if(queueHead->getP() < 1.5){
	enqueue(outQueueHead, dequeue(queueHead));
      }else if(queueHead->getData() != '(' && queueHead->getData() != ')'){
	while(stackHead != NULL && stackHead->getData() != '(' && stackHead->getP() >= queueHead->getP()){
	  enqueue(outQueueHead, pop(stackHead));
	}
	push(stackHead, dequeue(queueHead));
      }else if(queueHead->getData() == '('){
	push(stackHead, dequeue(queueHead));
      }else if(queueHead->getData() == ')'){
	if(stackHead == NULL){
	  //error, mismatched parentheses
	  continue;
	}
	while(stackHead->getData() != '('){
	  enqueue(outQueueHead, pop(stackHead));
	}
	pop(stackHead);
	pop(queueHead);
      }else{
	//error parsing, unreadable input
	continue;
      }
    }
    while(stackHead != NULL){
      if(stackHead->getData() == '('){
	//error, mismatched parentheses
	break;
      }else{
	enqueue(outQueueHead, pop(stackHead));
      }
    }

    //tree builder
    while(outQueueHead != NULL){
      Node* node = new Node(outQueueHead->getData());
      if(outQueueHead->getP() < 1.5){
	push(treeStackHead, node);
      }else{
	node->setRight(pop(treeStackHead));
	node->setLeft(pop(treeStackHead));
	push(treeStackHead, node);
      }
      outQueueHead = outQueueHead->getNext();
    }
    cout << "tree built" << endl;
    //tree built
    while(true){
      cout << "Choose infix, postfix, prefix notation, or to quit" << endl;
      cin.clear();
      cin >> terminal;
      for(int i = 0; i < strlen(terminal); i++){
	if(!isalpha(terminal[i])){
	  memmove(terminal+i, terminal+1+i, strlen(terminal)-1-i);
	  terminal[strlen(terminal)-1] = '\0';
	  i--;
	}
      }
      //assume good inputs on infix/postfix/prefix options
      if(!strcmp(terminal, "infix")){
	infix(treeStackHead);
      }else if(!strcmp(terminal, "postfix")){
	postfix(treeStackHead);
      }else if(!strcmp(terminal, "prefix")){
	prefix(treeStackHead);
      }else if(!strcmp(terminal, "quit")){
	return 0;
      }else{
	cout << "Bad input" << endl;
	continue;
      }
      cout << endl;
    }
  }
}
//print out in infix notation
void infix(Node* treeHead){
  if(treeHead->getLeft() != NULL){
    infix(treeHead->getLeft());
  }
  cout << treeHead->getData() << " ";
  if(treeHead->getRight() != NULL){
    infix(treeHead->getRight());
  }
}
//print out in postfix notation
void postfix(Node* treeHead){
  if(treeHead->getLeft() != NULL){
    postfix(treeHead->getLeft());
  }
  if(treeHead->getRight() != NULL){
    postfix(treeHead->getRight());
  }
  cout << treeHead->getData() << " ";
}
//print out in prefix notation
void prefix(Node* treeHead){
  cout << treeHead->getData() << " ";
  if(treeHead->getLeft() != NULL){
    prefix(treeHead->getLeft());
  }
  if(treeHead->getRight() != NULL){
    prefix(treeHead->getRight());
  }
}

//stack functions
void push(Node* &head, Node* node){
  if(head != NULL){
    node->setNext(head);
  }
  head = node;
}

Node* pop(Node* &head){
  if(head == NULL){
    cout << "Nothing to pop off!" << endl;
    return NULL;
  }else{
    Node* node = head;
    if(head->getNext() != NULL){
      head = head->getNext();
    }else{
      head = NULL;
    }
    Node* nodeN = NULL;
    node->setNext(nodeN);
    return node;
  }
}

int peek(Node* &head, char c){
  Node* currentNode = head;
  while(currentNode != NULL){
    if(currentNode->getData() == c){
      return currentNode->getP();
    }else if(currentNode->getNext() == NULL){
      cout << "No node to peek at with that value!" << endl;
      return -1;
    }else{
      currentNode = currentNode->getNext();
    }
  }
  return -1;
}

//queue functions
void enqueue(Node* &head, Node* node){
  if(node != NULL){
    Node* nodeN = NULL;
    node->setNext(nodeN);
  }
  if(head != NULL){
    Node* currentNode = head;
    while(currentNode != NULL){
      if(currentNode->getNext() != NULL){
	currentNode = currentNode->getNext();
      }else{
	currentNode->setNext(node);
	return;
      }
    }
  }else{
    head = node;
  }
}

Node* dequeue(Node* &head){
  if(head == NULL){
    cout << "Q empty!" << endl;
    return NULL;
  }else{
    Node* node = head;
    head = head->getNext();
    return node;
  }
}

//ps: this code was annoying and so are you XD
