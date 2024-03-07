#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(char a){
  left = NULL;
  right = NULL;
  data = a;
  p = -1;
}

Node::~Node(){
  
}

void Node::setLeft(Node* node){
  left = node;
}

void Node::setRight(Node* node){
  right = node;
}

void Node::setNext(Node* node){
  next = node;
}

Node* Node::getLeft(){
  return left;
}

Node* Node::getRight(){
  return right;
}

Node* Node::getNext(){
  return next;
}

char Node::getData(){
  return data;
}

void Node::setP(int p1){
  p = p1;
}

int Node::getP(){
  return p;
}
