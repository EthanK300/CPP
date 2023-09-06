#include <iostream>
#include <cstring>
using namespace std;

bool checkWin(char intake[3][3]);

const char XMOVE = 'X';
const char OMOVE = 'O';
const char BLANK = '-';

int main(){
  bool playing = true;
  bool valid = false;
  char turn = 'X';
  cout << "This is the board." << endl;
  char board[3][3] = {{BLANK,BLANK,BLANK},{BLANK,BLANK,BLANK},{BLANK,BLANK,BLANK}};
  char guess[3];
  
  while(playing){
    cout << endl << "  A B C" << endl << "A " << board[0][0] << " " << board[0][1] << " " << board[0][2]
	 << endl << "B " << board[1][0] << " " << board[1][1] << " " << board[1][2]
	 << endl << "C " << board[2][0] << " " << board[2][1] << " " << board[2][2] << endl;
    cout << "It is player " << turn << "'s turn." << endl;
    
    while(!valid){
      cout << "Enter a letter followed by a number for position: ";
      cin.clear();
      cin >> guess;
      cin.ignore(10000, '\n');
      if(isalpha(guess[0]) && isalpha(guess[1])){
        valid = true;
      }
    }
    valid = false;

    cout << guess << " Nice." << endl;
    
  }
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
    return true;
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
    return true;
  }
  //diagonals
  if(intake[0][0] == XMOVE && intake[1][1] == XMOVE && intake[2][2] == XMOVE){
    cout << "Player X has won!";
    return true;
  }
  if(intake[0][2] == XMOVE && intake[1][1] == XMOVE && intake[3][0] == XMOVE){
    cout << "Player X has won!";
    return true;
  }
  //O player
  //columns
  if(intake[0][0] == OMOVE && intake[0][1] == OMOVE && intake[0][2] == OMOVE){
    cout << "Player O has won!";
    return true;
  }
  if(intake[1][0] == OMOVE && intake[1][1] == OMOVE && intake[1][2] == OMOVE){
    cout << "Player O has won!";
    return true;
  }
  if(intake[2][0] == OMOVE && intake[2][1] == OMOVE && intake[2][2] == OMOVE){
    cout << "Player O has won!";
    return true;
  }
  //rows
  if(intake[0][0] == OMOVE && intake[1][0] == OMOVE && intake[2][0] == OMOVE){
    cout << "Player O has won!";
    return true;
  }
  if(intake[0][1] == OMOVE && intake[1][1] == OMOVE && intake[2][1] == OMOVE){
    cout << "Player O has won!";
    return true;
  }
  if(intake[0][2] == OMOVE && intake[1][2] == OMOVE && intake[2][2] == OMOVE){
    cout << "Player O has won!";
    return true;
  }
  //diagonals
  if(intake[0][0] == OMOVE && intake[1][1] == OMOVE && intake[2][2] == OMOVE){
    cout << "Player O has won!";
    return true;
  }
  if(intake[0][2] == OMOVE && intake[1][1] == OMOVE && intake[3][0] == OMOVE){
    cout << "Player O has won!";
    return true;
  }
  return false;
}
