#include "Node.h"
#include <iostream>
#include <cstring>
using namespace std;
Node::Node(){
  ID = -1;
  left = NULL;
  right = NULL;
}

Node::Node(int intake){
  ID = intake;
  left = NULL;
  right = NULL;
}

Node::~Node(){

}

void Node::setLeft(Node* intake){
  left = intake;
}

void Node::setRight(Node* intake){
  right = intake;
}

Node* Node::getLeft(){
  return left;
}

Node* Node::getRight(){
  return right;
}

int Node::getID(){
  return ID;
}
