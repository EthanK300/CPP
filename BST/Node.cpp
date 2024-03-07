#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(int a){
  data = a;
  sChild = NULL;
  bChild = NULL;
}

Node::~Node(){
  
}

void Node::setbChild(Node* node){
  bChild = node;
}

void Node::setsChild(Node* node){
  sChild = node;
}

Node* Node::getbChild(){
  return bChild;
}

Node* Node::getsChild(){
  return sChild;
}

int Node::getData(){
  return data;
}
