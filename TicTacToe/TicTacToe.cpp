#include <iostream>
#include <cstring>
using namespace std;

bool checkWin(char intake[3][3]);
char XMOVE = 'X';
char OMOVE = 'O';

int main(){
  char board[3][3];
  
}

bool checkWin(char intake[3][3]){
  //columns
  if(intake[0][0] == XMOVE && intake[0][1] == XMOVE && intake[0][2] == XMOVE){
    cout << "Player X has won!";
    return true;
  }
  if(intake[1][0] == XMOVE && intake[1][1] == XMOVE && intake[1][2] == XMOVE){
    cout << "Player X has won!";
    return true;
  }
  if(intake[2][0] == XMOVE && intake[2][1] == XMOVE && intake[2][2] == XMOVE){
    cout << "Player X has won!";
  }
  //rows
  if(intake[0][0] == XMOVE && intake[1][0] == XMOVE && intake[2][0] == XMOVE){
    cout << "Player X has won!";
    return true;
  }
  if(intake[0][1] == XMOVE && intake[1][1] == XMOVE && intake[2][1] == XMOVE){
    cout << "Player X has won!";
    return true;
  }
  if(intake[0][2] == XMOVE && intake[1][2] == XMOVE && intake[2][2] == XMOVE){
    cout << "Player X has won!";
  }
  //diagonals
  if(intake[0][0] == XMOVE && intake[1][1] == XMOVE && intake[2][2] == XMOVE){
    cout << "Player X has won!";
  }
  if(intake[0][2] == XMOVE && intake[1][1] == XMOVE && intake[3][0] == XMOVE){
    cout << "Player X has won!";
  }
  //O player
  //columns
  if(intake[0][0] == XMOVE && intake[0][1] == XMOVE && intake[0][2] == XMOVE){
    cout << "Player X has won!";
    return true;
  }
  if(intake[1][0] == XMOVE && intake[1][1] == XMOVE && intake[1][2] == XMOVE){
    cout << "Player X has won!";
    return true;
  }
  if(intake[2][0] == XMOVE && intake[2][1] == XMOVE && intake[2][2] == XMOVE){
    cout << "Player X has won!";
  }
  //rows
  if(intake[0][0] == XMOVE && intake[1][0] == XMOVE && intake[2][0] == XMOVE){
    cout << "Player X has won!";
    return true;
  }
  if(intake[0][1] == XMOVE && intake[1][1] == XMOVE && intake[2][1] == XMOVE){
    cout << "Player X has won!";
    return true;
  }
  if(intake[0][2] == XMOVE && intake[1][2] == XMOVE && intake[2][2] == XMOVE){
    cout << "Player X has won!";
  }
  //diagonals
  if(intake[0][0] == XMOVE && intake[1][1] == XMOVE && intake[2][2] == XMOVE){
    cout << "Player X has won!";
  }
  if(intake[0][2] == XMOVE && intake[1][1] == XMOVE && intake[3][0] == XMOVE){
    cout << "Player X has won!";
  }
}
