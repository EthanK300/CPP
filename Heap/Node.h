#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
class Node{
 public:
  Node();
  Node(int intake);
  ~Node();
  void setLeft(Node* intake);
  void setRight(Node* intake);
  Node* getLeft();
  Node* getRight();
  int getID();
 protected:
  Node* left;
  Node* right;
  int ID;
};
#endif
