#include <iostream>
#include <cstring>
#include "Node.h"
#include <fstream>

using namespace std;
/*
a: ethan k
binary search tree: yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy sticking numbers in ordering left is small right is big and make functions to interact with data in tree
*/

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
      cout << "Enter number" << endl;
      cin >> terminal;
      int num = atoi(terminal);
      cout << "A message will appear if your number is present in the tree." << endl;
      SEARCH(root, num);
    }else if(!strcmp(terminal, "ADD")){
      cout << "Enter number" << endl;
      cin >> terminal;
      int num = atoi(terminal);
      Node* node = new Node(num);
      ADD(root, node);
    }else if(!strcmp(terminal, "PRINT")){
      PRINT(root, 0);
    }else if(!strcmp(terminal, "DELETE")){
      cout << "Enter number" << endl;
      cin >> terminal;
      int num = atoi(terminal);
      DELETE(root, num);
    }else if(!strcmp(terminal, "QUIT")){
      cout << "quitted." << endl;
      return 0;
    }else if(!strcmp(terminal, "FILL")){
      FILL(root);
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
  if(root->getsChild() != NULL){
    PRINT(root->getsChild(), count + 1);
  }
  for( int i = 0; i < count; i++){
    cout << '\t';
  }
  cout << root->getData() << endl;
  if(root->getbChild() != NULL){
    PRINT(root->getbChild(), count + 1);
  }
}

void DELETE(Node* &root, int value){
  if(root == NULL){
    cout << "Nothing to delete! Tree is empty." << endl;
  }else if(root->getData() == value){
    
  }else{
    Node* currentNode = root;
    Node* targetNode = NULL;
    Node* beforeNode = NULL;
    while(currentNode != NULL){
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
      if(currentNode2->getbChild() != NULL){
	beforeNode2->setsChild(currentNode2->getbChild());
	delete currentNode2;
      }else{
	delete currentNode2;
      }
    }else if(targetNode->getsChild() != NULL){
      //has smaller child
      beforeNode->setsChild(targetNode->getsChild());
      delete targetNode;
    }else{
      //has bigger child
      beforeNode->setbChild(targetNode->getbChild());
    }
  }
}

void FILL(Node* &root){
  cout << "Adding students from file" << endl;
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
