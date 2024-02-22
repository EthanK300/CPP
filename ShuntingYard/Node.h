#ifndef NODE
#define NODE
#include <iostream>
#include <cstring>
using namespace std;

class Node{
public:
  Node(char a);
  void setLeft(Node* &node);
  void setRight(Node* &node);
  Node* getLeft();
  Node* getRight();
  bool getOperation();
  char getData();
  void setOperation(bool o);
  ~Node();
protected:
  Node* left;
  Node* right;
  char data;
  bool isOperation;
};

#endif
