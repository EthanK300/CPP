#ifndef NODE
#define NODE
#include <iostream>
#include <cstring>
using namespace std;

class Node{
public:
  Node(int a);
  void setbChild(Node* node);
  void setsChild(Node* node);
  Node* getbChild();
  Node* getsChild();
  int getData();
  void setData(int a);
  ~Node();
protected:
  Node* bChild;
  Node* sChild;
  int data;
};

#endif
