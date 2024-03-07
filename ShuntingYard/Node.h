#ifndef NODE
#define NODE
#include <iostream>
#include <cstring>
using namespace std;

class Node{
public:
  Node(char a);
  void setNext(Node* node);
  void setLeft(Node* node);
  void setRight(Node* node);
  Node* getLeft();
  Node* getRight();
  Node* getNext();
  int getP();
  char getData();
  void setP(int p1);
  ~Node();
protected:
  Node* left;
  Node* right;
  Node* next;
  char data;
  int p;
};

#endif
