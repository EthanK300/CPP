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
    RED, BLACK, WHITE
    //white is considered null
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
    color = WHITE;
    left = NULL;
    right = NULL;
    parent = NULL;
  }

  ~Node(){
    
  }
  
  void setsChild(Node* node){
    left = node;
  }

  void setbChild(Node* node){
    right = node;
  }

  void setColor(Color::Color c){
    color = c;
  }

  void setData(int a){
    data = a;
  }
  
  Color::Color getColor(){
    return color;
  }

  Node* getsChild(){
    return left;
  }

  Node* getbChild(){
    return right;
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

void SEARCH(Node* root, int input);
void ADD(Node* &root, Node* node);
void DELETE(Node* &root, int value);
void FILL(Node* &root);
void PRINT(Node* root, int count);

int main(){
  Node* root = NULL;
  char terminal[80];
  cout << "Commands: ADD, FILL, PRINT, DELETE, SEARCH, QUIT" << endl;
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
    if(!strcmp(terminal, "SEARCH")){
      
    }else if(!strcmp(terminal, "ADD")){
      
    }else if(!strcmp(terminal, "PRINT")){
      
    }else if(!strcmp(terminal, "DELETE")){
      
    }else if(!strcmp(terminal, "FILL")){
      
    }else if(!strcmp(terminal, "QUIT")){
      return 0;
    }else{
      cout << "Bad Input." << endl;
    }
  }
}

void SEARCH(Node* root, int input){
  if(root->getsChild() != NULL){
    SEARCH(root->getsChild(), input);
  }
  if(root->getData() == input){
    cout << "Number is in tree." << endl;
  }
  if(root->getbChild() != NULL){
    SEARCH(root->getbChild(), input);
  }
}

void ADD(Node* &root, Node* node){
  if(root == NULL){
    root = node;
  }else{
    Node* currentNode = root;
    while(currentNode != NULL){
      if(node->getData() > currentNode->getData()){
	if(currentNode->getbChild() != NULL){
	  currentNode = currentNode->getbChild();
	}else{
	  currentNode->setbChild(node);
	  break;
	}
      }else{
	if(currentNode->getsChild() != NULL){
	  currentNode = currentNode->getsChild();
	}else{
	  currentNode->setsChild(node);
	  break;
	}
      }
    }
  }
}

void PRINT(Node* root, int count){
  if(root->getbChild() != NULL){
    PRINT(root->getbChild(), count + 1);
  }
  for( int i = 0; i < count; i++){
    cout << '\t';
  }
  cout << root->getData() << endl;
  if(root->getsChild() != NULL){
    PRINT(root->getsChild(), count + 1);
  }
}

void DELETE(Node* &root, int value){
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
      if(currentNode->getsChild() != NULL && currentNode->getData() > value){
	if(currentNode->getsChild()->getData() == value){
	  targetNode = currentNode->getsChild();
	  break;
	}else{
	  currentNode = currentNode->getsChild();
	}
      }else if(currentNode->getbChild() != NULL & currentNode->getData() < value){
	if(currentNode->getbChild()->getData() == value){
	  targetNode = currentNode->getbChild();
	  break;
	}else{
	  currentNode = currentNode->getbChild();
	}
      }else{
	if(currentNode->getsChild()->getData() == value){
	  targetNode = currentNode->getsChild();
	  break;
	}else{
	  currentNode = currentNode->getsChild();
	}
      }
    }
    //target node is the one to delete and is reference
    if(targetNode == root){
      if(root->getsChild() != NULL && root->getbChild() != NULL){
	//root has both children
	Node* rootB = root->getbChild();
	if(rootB->getsChild() == NULL){
	  root->setData(rootB->getData());
	  if(rootB->getbChild() != NULL){
	    root->setbChild(rootB->getbChild());
	    delete rootB;
	  }else{
	    root->setbChild(NULL);
	    delete rootB;
	  }
	}else{
	  Node* beforeB = rootB;
	  Node* beforeB2 = rootB;
	  while(beforeB != NULL){
	    if(beforeB->getsChild() != NULL){
	      beforeB2 = beforeB;
	      beforeB = beforeB->getsChild();
	    }else{
	      break;
	    }
	  }
	  root->setData(beforeB->getData());
	  if(beforeB->getbChild() != NULL){
	    beforeB2->setsChild(beforeB->getbChild());
	  }else{
	    beforeB2->setsChild(NULL);
	  }
	  delete beforeB;
	}
      }else if(root->getsChild() == NULL){
	//root only has b child
	root = root->getbChild();
	delete targetNode;
      }else if(root->getbChild() == NULL){
	//root only has s child
	root = root->getsChild();
	delete targetNode;
      }else{
	//root has no children
	root = NULL;
	delete targetNode;
      }
    }else{
      if(targetNode->getsChild() == NULL && targetNode->getbChild() == NULL){
	//no child
	if(beforeNode->getsChild() == targetNode){
	  //targetnode is left child
	  beforeNode->setsChild(NULL);
	  delete targetNode;
	}else{
	  //targetnode is right child
	  beforeNode->setbChild(NULL);
	  delete targetNode;
	}
      }else if(targetNode->getsChild() != NULL && targetNode->getbChild() != NULL){
	//has 2 child
	Node* currentNode2 = targetNode->getbChild();
	Node* beforeNode2 = targetNode->getbChild();
	while(currentNode2 != NULL){
	  if(currentNode2->getsChild() != NULL){
	    beforeNode2 = currentNode2;
	    currentNode2 = currentNode2->getsChild();
	  }else{
	    break;
	  }
	}
	targetNode->setData(currentNode2->getData());
	if(targetNode->getbChild()->getData() == currentNode2->getData()){
	  targetNode->setbChild(NULL);
	}
	if(currentNode2->getbChild() != NULL){
	  beforeNode2->setsChild(currentNode2->getbChild());
	  delete currentNode2;
	}else{
	  delete currentNode2;
	}
      }else if(targetNode->getsChild() != NULL){
	//has smaller child
	if(beforeNode->getsChild() == targetNode){
	  beforeNode->setsChild(targetNode->getsChild());
	  delete targetNode;
	}else{
	  beforeNode->setbChild(targetNode->getsChild());
	  delete targetNode;
	}
      }else{
	//has bigger child
	if(beforeNode->getsChild() == targetNode){
	  beforeNode->setsChild(targetNode->getbChild());
	  delete targetNode;
	}else{
	  beforeNode->setbChild(targetNode->getbChild());
	  delete targetNode;
	}
      }
    }
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
