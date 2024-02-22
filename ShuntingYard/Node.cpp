#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(char a){
  left = NULL;
  right = NULL;
  data = a;
}

Node::~Node(){
  
}

void Node::setLeft(Node* &node){
  left = node;
}

void Node::setRight(Node* &node){
  right = node;
}

Node* Node::getLeft(){
  return left;
}

Node* Node::getRight(){
  return right;
}

char Node::getData(){
  return data;
}

void Node::setOperation(bool o){
  isOperation = o;
}

bool Node::getOperation(){
  return isOperation;
}
