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
void updateTreeD(Node* &root, Color::Color u, Color::Color v, Node* parent, bool isLeft);
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
  Color::Color u = BLACK; //u is the one being deleted
  Color::Color v; //v is the child of one being deleted
  bool isLeft = NULL;
  Node* parent = NULL;
  if(root == NULL){
    cout << "Nothing to delete! Tree is empty." << endl;
  }else{
    Node* currentNode = root;
    Node* targetNode = NULL;
    Node* beforeNode = NULL;
    while(currentNode != NULL){
      if(root->getData() == value){
	targetNode = root;
	beforeNode = NULL;
	break;
      }
      beforeNode = currentNode;
      if(currentNode->getL() != NULL && currentNode->getData() > value){
	if(currentNode->getL()->getData() == value){
	  targetNode = currentNode->getL();
	  break;
	}else{
	  currentNode = currentNode->getL();
	}
      }else if(currentNode->getR() != NULL & currentNode->getData() < value){
	if(currentNode->getR()->getData() == value){
	  targetNode = currentNode->getR();
	  break;
	}else{
	  currentNode = currentNode->getR();
	}
      }else{
	if(currentNode->getL()->getData() == value){
	  targetNode = currentNode->getL();
	  break;
	}else{
	  currentNode = currentNode->getL();
	}
      }
    }
    //target node is the one to delete and is reference
    if(targetNode == root){
      v = root->getColor();
      if(root->getL() != NULL && root->getR() != NULL){
	//root has both children
	Node* rootB = root->getR();
	if(rootB->getL() == NULL){
	  root->setData(rootB->getData());
	  if(rootB->getR() != NULL){
	    u = rootB->getColor();
	    root->setR(rootB->getR());
	    delete rootB;
	  }else{
	    u = rootB->getColor();
	    root->setL(NULL);
	    delete rootB;
	  }
	}else{
	  Node* beforeB = rootB;
	  Node* beforeB2 = rootB;
	  while(beforeB != NULL){
	    if(beforeB->getL() != NULL){
	      beforeB2 = beforeB;
	      beforeB = beforeB->getL();
	    }else{
	      break;
	    }
	  }
	  root->setData(beforeB->getData());
	  if(beforeB->getR() != NULL){
	    u = beforeB->getR()->getColor();
	    beforeB2->setL(beforeB->getR());
	  }else{
	    beforeB2->setL(NULL);
	  }
	  v = beforeB->getColor();
	  delete beforeB;
	}
      }else if(root->getL() == NULL){
	u = root->getR()->getColor();
	//root only has b child
	root = root->getR();
	delete targetNode;
      }else if(root->getR() == NULL){
	//root only has s child
	u = root->getL()->getColor();
	root = root->getL();
	delete targetNode;
      }else{
	//root has no children
	root = NULL;
	delete targetNode;
      }
    }else{
      v = targetNode->getColor();
      if(targetNode->getL() == NULL && targetNode->getR() == NULL){
	//no child
	v = BLACK;
	parent = beforeNode;
	if(beforeNode->getL() == targetNode){
	  //targetnode is left child
	  isLeft = true;
	  beforeNode->setL(NULL);
	  delete targetNode;
	}else{
	  //targetnode is right child
	  isLeft = false;
	  beforeNode->setR(NULL);
	  delete targetNode;
	}
      }else if(targetNode->getL() != NULL && targetNode->getR() != NULL){
	//has 2 child
	Node* currentNode2 = targetNode->getR();
	Node* beforeNode2 = targetNode->getR();
	while(currentNode2 != NULL){
	  if(currentNode2->getL() != NULL){
	    beforeNode2 = currentNode2;
	    currentNode2 = currentNode2->getL();
	  }else{
	    break;
	  }
	}
	parent = beforeNode2;
	isLeft = true;
	targetNode->setData(currentNode2->getData());
	if(targetNode->getR()->getData() == currentNode2->getData()){
	  targetNode->setR(NULL);
	}
	if(currentNode2->getR() != NULL){
	  beforeNode2->setL(currentNode2->getR());
	  delete currentNode2;
	}else{
	  beforeNode2->setL(NULL);
	  delete currentNode2;
	}
      }else if(targetNode->getL() != NULL){
	parent = beforeNode;
	isLeft = true;
	//has smaller child
	u = targetNode->getL()->getColor();
	if(beforeNode->getL() == targetNode){
	  beforeNode->setL(targetNode->getL());
	  delete targetNode;
	}else{
	  beforeNode->setR(targetNode->getL());
	  delete targetNode;
	}
      }else{
	parent = beforeNode;
	isLeft = false;
	//has bigger child
	u = targetNode->getR()->getColor();
	if(beforeNode->getL() == targetNode){
	  beforeNode->setL(targetNode->getR());
	  delete targetNode;
	}else{
	  beforeNode->setR(targetNode->getR());
	  delete targetNode;
	}
      }
    }
  }
  updateTreeD(root, u, v, parent, isLeft);
}


void updateTreeD(Node* &root, Color::Color u, Color::Color v, Node* parent, bool isLeft){
  if(parent == NULL){
    root->setColor(BLACK);
    return;
  }
  if(v == BLACK && u == BLACK){
    //double black case
    //create references
    Node* p = parent;
    Node* g = parent->getP();
    Node* s = NULL;
    if(isLeft){
      s = p->getR();
    }else{
      s = p->getL();
    }
    //cases
    if(s->getColor() == BLACK && (s->getL() != NULL && s->getL()->getColor() == RED || s->getR() != NULL && s->getR()->getColor() == RED)){
      //sibling one red child case
      Node* r = s->getL()->getColor() == RED ? s->getL() : s->getR();
      if(s == p->getR()){
	if(r == s->getR()){
	  //rr
	  
	}else{
	  //rl
	  
	}
      }else{
	if(r == s->getR()){
	  //lr
	  
	}else{
	  //ll
	  
	}
      }
    }else{
      //sibling no red children case
      
    }
    
  }else if(isLeft == true){
    parent->getL()->setColor(BLACK);
    //simple case
  }else if(isLeft == false){
    parent->getR()->setColor(BLACK);
  }else{
    cout << "Error" << endl;
    return;
  }
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
