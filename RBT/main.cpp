#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
/*
a: ethan k
create rbt functionality
*/
namespace Color{
  enum Color{
    RED, BLACK
  };
};

using namespace Color;

class Node{
 public:
  Node(int a, Color::Color c){
    data = a;
    color = c;
    left = NULL;
    right = NULL;
    parent = NULL;
  }

  Node(int a){
    data = a;
    color = RED;
    left = NULL;
    right = NULL;
    parent = NULL;
  }

  ~Node(){
    
  }
  
  void setL(Node* node){
    left = node;
  }

  void setR(Node* node){
    right = node;
  }

  void setColor(Color::Color c){
    color = c;
  }

  void setP(Node* node){
    parent = node;
  }

  void setData(int a){
    data = a;
  }
  
  Color::Color getColor(){
    return color;
  }

  Node* getL(){
    return left;
  }

  Node* getR(){
    return right;
  }

  Node* getP(){
    return parent;
  }

  int getData(){
    return data;
  }
  
 protected:
  int data;
  Color::Color color;
  Node* parent;
  Node* left;
  Node* right;
};

void ADD(Node* &root, Node* node);
void DELETE(Node* &root, int value);
void FILL(Node* &root);
void PRINT(Node* root, int count);
void updateTreeA(Node* &root, Node* node);
void updateTreeD(Node* &root);
void rotateLeft(Node* &root, Node* node);
void rotateRight(Node* &root, Node* node);


int main(){
  Node* root = NULL;
  char terminal[80];
  cout << "Commands: ADD, FILL, PRINT, DELETE, QUIT" << endl;
  while(true){
    cout << "Enter command:" << endl;
    cin.clear();
    cin >> terminal;
    for(int i = 0; i < strlen(terminal); i++){
      if(!isalpha(terminal[i])){
        memmove(terminal+i, terminal+1+i, strlen(terminal)-1-i);
	terminal[strlen(terminal)-1] = '\0';
        i--;
      }
    }
    //assume good inputs
    if(!strcmp(terminal, "ADD")){
      cout << "Enter number: " << endl;
      cin >> terminal;
      int num = atoi(terminal);
      Node* node = new Node(num);
      ADD(root, node);
      updateTreeA(root, node);
    }else if(!strcmp(terminal, "PRINT")){
      if(root == NULL){
	cout << "Nothing to print. No nodes in tree!" << endl;
	continue;
      }
      PRINT(root, 0);
    }else if(!strcmp(terminal, "DELETE")){
      cout << "Enter number: " << endl;
      cin >> terminal;
      int num = atoi(terminal);
      DELETE(root, num);
      updateTreeD(root);
    }else if(!strcmp(terminal, "FILL")){
      FILL(root);
    }else if(!strcmp(terminal, "QUIT")){
      return 0;
    }else{
      cout << "Bad Input." << endl;
    }
  }
}

void ADD(Node* &root, Node* node){
  if(root == NULL){
    root = node;
  }else{
    Node* currentNode = root;
    while(currentNode != NULL){
      if(node->getData() > currentNode->getData()){
	if(currentNode->getR() != NULL){
	  currentNode = currentNode->getR();
	}else{
	  currentNode->setR(node);
	  node->setP(currentNode);
	  break;
	}
      }else{
	if(currentNode->getL() != NULL){
	  currentNode = currentNode->getL();
	}else{
	  currentNode->setL(node);
	  node->setP(currentNode);
	  break;
	}
      }
    }
  }
}

void updateTreeA(Node* &root, Node* node){
  Node* p = NULL;
  Node* g = NULL;
  Node* gg = NULL;
  Node* s = NULL;
  Node* u = NULL;
  //creation of family tree for fast reference variables
  if(node != root){
    p = node->getP();
    if(p != NULL){
      g = p->getP();
      if(node == p->getL()){
	s = p->getR();
      }else{
	s = p->getL();
      }
      if(g != NULL){
	gg = g->getP();
	if(p == g->getL()){
	  u = g->getR();
	}else{
	  u = g->getL();
	}
      }
    }
  }
  //tree updating
  if(node->getP() == NULL){
    node->setColor(BLACK);
    return;
  }else if(p->getColor() == BLACK){
    return;
  }else{
    if(u != NULL && u->getColor() == RED){
      //recolor
      p->setColor(BLACK);
      u->setColor(BLACK);
      g->setColor(RED);
      updateTreeA(root, g);
    }else{
      //rotate and then recolor
      if(p == g->getL()){
	if(node == p->getR()){
	  //LR
	  rotateLeft(root, p);
	  rotateRight(root, g);
	  node->setColor(BLACK);
	}else{
	  //LL
	  rotateRight(root ,g);
	  p->setColor(BLACK);
	}
	g->setColor(RED);
      }else{
	if(node == p->getL()){
	  //RL
	  rotateRight(root, p);
	  rotateLeft(root, g);
	  node->setColor(BLACK);
	}else{
	  //RR
	  rotateLeft(root, g);
	  p->setColor(BLACK);
	}
	g->setColor(RED);
      }
    }
  }
}

void rotateLeft(Node* &root, Node* node){
  Node* gg = NULL;
  Node* p = NULL;
  Node* s = NULL;
  p = node->getR();
  s = p->getL();
  gg = node->getP();
  if(root == node){
    root = p;
  }else if(gg->getR() == node){
    gg->setR(p);
  }else{
    gg->setL(p);
  }
  p->setP(gg);
  p->setL(node);
  node->setR(s);
  if(s != NULL){
    s->setP(node);
  }
  node->setP(p);
}

void rotateRight(Node* &root, Node* node){
  Node* gg = NULL;
  Node* p = NULL;
  Node* s = NULL;
  p = node->getL();
  s = p->getR();
  gg = node->getP();
  if(root == node){
    root = p;
  }else if(gg->getL() == node){
    gg->setL(p);
  }else{
    gg->setR(p);
  }
  p->setP(gg);
  p->setR(node);
  node->setL(s);
  if(s != NULL){
    s->setP(node);
  }
  node->setP(p);
}

void PRINT(Node* root, int count){
  if(root->getR() != NULL){
    PRINT(root->getR(), count + 1);
  }
  for( int i = 0; i < count; i++){
    cout << '\t';
  }
  if(root->getColor() == BLACK){
    cout << "B";
  }else{
    cout << "R";
  }
  cout << ":";
  cout << root->getData() << endl;
  if(root->getL() != NULL){
    PRINT(root->getL(), count + 1);
  }
}

void DELETE(Node* &root, int value){

}

void updateTreeD(Node* &root){
  
}

void FILL(Node* &root){
  cout << "Adding numbers from file" << endl;
  ifstream nums;
  nums.open("numbers.txt");
  char* input = new char[80];
  while(nums >> input){
    char* temp = new char[80];
    strcpy(temp, input);
    int n = atoi(temp);
    Node* node = new Node(n);
    ADD(root, node);
  }
}
