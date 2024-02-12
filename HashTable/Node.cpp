#include "Node.h"
#include <iostream>
#include <cstring>
using namespace std;
Node::Node(Student* INstudent) {
  student = INstudent;
  next = NULL;
}
Node::~Node() {
  delete student;
}

void Node::setNext(Node* INnode) {
  next = INnode;
}
Node* Node::getNext() {
  return next;
}
Student* Node::getStudent() {
  return student;
}
