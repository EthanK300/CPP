#ifndef NODE_H
#define NODE_H
#include "Student.h"
#include <iostream>
using namespace std;
class Node {
 public:
  Node(Student*);
  ~Node();
  void setNext(Node* newnext);
  Node* getNext();
  Student* getStudent();
 protected:
  Student* student;
  Node* next;
};
#endif
