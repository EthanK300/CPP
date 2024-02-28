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
  Node* outQueueHead = NULL;
  Node* treeHead = NULL;
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
      if(node->getData() == '^'){
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
  }
}

void push(Node* &head, Node* node){
  if(head != NULL){
    node->setLeft(head);
  }
  head = node;
}

Node* pop(Node* &head){
  if(head == NULL){
    cout << "Nothing to pop off!" << endl;
    return NULL;
  }else{
    Node* node = head;
    if(head->getLeft() != NULL){
      head = head->getLeft();
    }else{
      head = NULL;
    }
    return node;
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
  if(head != NULL){
    node->setRight(head);
  }
  head = node;
}

Node* dequeue(Node* &head){
  if(head == NULL){
    cout << "Q empty!" << endl;
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
