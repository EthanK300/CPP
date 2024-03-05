#ifndef NODE
#define NODE
#include <iostream>
#include <cstring>
using namespace std;

class Node{
public:
  Node(char a);
  void setLeft(Node* node);
  void setRight(Node* node);
  Node* getLeft();
  Node* getRight();
  int getP();
  char getData();
  void setP(int p1);
  ~Node();
protected:
  Node* left;
  Node* right;
  char data;
  int p;
};

#endif
