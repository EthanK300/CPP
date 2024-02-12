#include <iostream>
#include <cstring>
#include "Node.h"
#include <fstream>

using namespace std;

void ADD(Node* &root, Node* intake);
void DELETE(Node* &root);
void DISPLAYTREE(Node* root);
void FILL(Node* &root);

int main(){
  Node* root = NULL;
  char terminal[80];
  cout << "List of commands: ADD, DISPLAYTREE, DELETE, FILL, QUIT" << endl;
  while(true){
    cout << "Enter a command: " << endl;
    cin.clear();
    cin >> terminal;
    for(int i = 0; i < strlen(terminal); i++){
      if(!isalpha(terminal[i])){
	memmove(terminal+i, terminal+1+i, strlen(terminal)-i);
	i--;
      }
    }
    //assume good input
    if(!strcmp(terminal, "ADD")){
      Node* node = new Node();
      ADD(root, node);
    }else if(!strcmp(terminal, "DISPLAYTREE")){
      DISPLAYTREE(root);
    }else if(!strcmp(terminal, "DELETE")){
      DELETE(root);
    }else if(!strcmp(terminal, "RANDOM")){
      FILL(root);
    }else if(!strcmp(terminal, "QUIT")){
      cout << "Quitted" << endl;
      return 0;
    }else{
      cout << "Bad Input" << endl;
    }
  }
}

void ADD(Node* &root, Node* intake){
  int id = intake->getID();
  Node* currentRoot = root;
  if(root == NULL){
    root = intake;
  }else{
    
  }
}

void DELETE(Node* &root){

}

void DISPLAYTREE(Node* root){

}

void FILL(Node* &root){

}
