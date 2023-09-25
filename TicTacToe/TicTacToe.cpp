#include <iostream>
#include <cstring>
using namespace std;

/*
Author: Ethan K
TicTacToe
Uses the console for UI and input
 */

int checkWin(char intake[3][3]);
bool checkTie(char intake[3][3]);
int playAgain();

const char XMOVE = 'X';
const char OMOVE = 'O';
const char BLANK = '-';

int main(){
  char terminal[3];
  int scoreO = 0;
  int scoreX = 0;
  int ties = 0;
  bool playing = true;
  bool valid = false;
  char turn = 'X';
  cout << "This is the board." << endl;
  char board[3][3] = {{BLANK,BLANK,BLANK},{BLANK,BLANK,BLANK},{BLANK,BLANK,BLANK}};
  char guess[3];
  int x = 0;
  int y = 0;
  //initialized all neccesary variables
  
  while(playing){
    //main game loop
    cout << endl << "  1 2 3" << endl << "A " << board[0][0] << " " << board[0][1] << " " << board[0][2]
	 << endl << "B " << board[1][0] << " " << board[1][1] << " " << board[1][2]
	 << endl << "C " << board[2][0] << " " << board[2][1] << " " << board[2][2] << endl;
    if(checkWin(board) == 0){
      scoreO++;
      cout << "X Score: " << scoreX << ", O Score: " << scoreO << " , Ties: " << ties << ", New Game!" << endl; 
      for(int x = 0; x < 3; x++){
	for(int y = 0; y < 3; y++){
	  board[x][y] = BLANK;
	}
      }
      turn = 'X';
      if(playAgain() == 0){
	return 0;
      }
    }else if(checkWin(board) == 1){
      scoreX++;
      cout << "X Score: " << scoreX << ", O Score: " << scoreO << " , Ties: " << ties << ", New Game!" << endl; 
      for(int x = 0; x < 3; x++){
	for(int y = 0; y < 3; y++){
	  board[x][y] = BLANK;
	}
      }
      turn = 'X';
      if(playAgain() == 0){
	return 0;
      }
    }
    if(checkTie(board)){
      ties++;
      cout << "X Score: " << scoreX << ", O Score: " << scoreO << " , Ties: " << ties << ", New Game!" <<endl;
      for(int x = 0; x < 3; x++){
	for(int y = 0; y < 3; y++){
	  board[x][y] = BLANK;
	}
      }
      turn = 'X';
      if(playAgain() == 0){
	return 0;
      }
    }
    //after checking for wins and ties, start new game and record scores
    cout << "It is player " << turn << "'s turn." << endl;
    
    while(!valid){
      //parsing for correct input
      cout << "Enter a number followed by a letter for an open position: ";
      cin.clear();
      cin >> guess;
      cin.ignore(10000, '\n');
      cout << guess << endl;
      if(isdigit(guess[0]) && isalpha(guess[1])){
	strlwr(guess);
	if(guess[0] == '1'){
	  y = 0;
	}else if(guess[0] == '2'){
	  y = 1;
	}else if(guess[0] == '3'){
	  y = 2;
	}else{
	  cout << "Bad Input, try again" << endl;
	}
	if(guess[1] == 'a'){
	  x = 0;
	}else if(guess[1] == 'b'){
	  x = 1;
	}else if(guess[1] == 'c'){
	  x = 2;
	}else{
	  cout << "Bad Input, try again" << endl;
	}
	if(board[x][y] == BLANK){
	  valid = true;
	}else{
	  cout << "Space is filled! Pick a different slot." << endl;
	}
	strcpy(guess, "");
      }
    }
    valid = false;
    
    //once acquired a good input, stick it on the board
    board[x][y] = turn;
    if(turn == XMOVE){
      turn = OMOVE;
    }else if(turn == OMOVE){
      turn = XMOVE;
    }else{
      cout << "Error";
      return 0;
    }
  }
}
//function to check if user wants to play again
int playAgain(){
  char terminal[80];
  cout << "Continue? y/n" << endl;
  cin.clear();
  cin >> terminal;
  if(!strcmp(terminal, "y")){
    return 1;	
  }else{
    return 0;
  }
}

//function to check for ties
bool checkTie(char intake[3][3]){
  for(int i = 0; i < strlen(intake[0]); i++){
    for(int j = 0; j < strlen(intake[0]); j++){
      if(intake[i][j] == BLANK){
	return false;
      }
    }
  }
  cout << "Tie!" << endl;
  return true;
}

//returns 1 if X won and 0 if O won
int checkWin(char intake[3][3]){
  //columns
  if(intake[0][0] == XMOVE && intake[0][1] == XMOVE && intake[0][2] == XMOVE){
    cout << "Player X has won!";
    return 1;
  }
  if(intake[1][0] == XMOVE && intake[1][1] == XMOVE && intake[1][2] == XMOVE){
    cout << "Player X has won!";
    return 1;
  }
  if(intake[2][0] == XMOVE && intake[2][1] == XMOVE && intake[2][2] == XMOVE){
    cout << "Player X has won!";
    return 1;
  }
  //rows
  if(intake[0][0] == XMOVE && intake[1][0] == XMOVE && intake[2][0] == XMOVE){
    cout << "Player X has won!";
    return 1;
  }
  if(intake[0][1] == XMOVE && intake[1][1] == XMOVE && intake[2][1] == XMOVE){
    cout << "Player X has won!";
    return 1;
  }
  if(intake[0][2] == XMOVE && intake[1][2] == XMOVE && intake[2][2] == XMOVE){
    cout << "Player X has won!";
    return 1;
  }
  //diagonals
  if(intake[0][0] == XMOVE && intake[1][1] == XMOVE && intake[2][2] == XMOVE){
    cout << "Player X has won!";
    return 1;
  }
  if(intake[0][2] == XMOVE && intake[1][1] == XMOVE && intake[3][0] == XMOVE){
    cout << "Player X has won!";
    return 1;
  }
  //O player
  //columns
  if(intake[0][0] == OMOVE && intake[0][1] == OMOVE && intake[0][2] == OMOVE){
    cout << "Player O has won!";
    return 0;
  }
  if(intake[1][0] == OMOVE && intake[1][1] == OMOVE && intake[1][2] == OMOVE){
    cout << "Player O has won!";
    return 0;
  }
  if(intake[2][0] == OMOVE && intake[2][1] == OMOVE && intake[2][2] == OMOVE){
    cout << "Player O has won!";
    return 0;
  }
  //rows
  if(intake[0][0] == OMOVE && intake[1][0] == OMOVE && intake[2][0] == OMOVE){
    cout << "Player O has won!";
    return 0;
  }
  if(intake[0][1] == OMOVE && intake[1][1] == OMOVE && intake[2][1] == OMOVE){
    cout << "Player O has won!";
    return 0;
  }
  if(intake[0][2] == OMOVE && intake[1][2] == OMOVE && intake[2][2] == OMOVE){
    cout << "Player O has won!";
    return 0;
  }
  //diagonals
  if(intake[0][0] == OMOVE && intake[1][1] == OMOVE && intake[2][2] == OMOVE){
    cout << "Player O has won!";
    return 0;
  }
  if(intake[0][2] == OMOVE && intake[1][1] == OMOVE && intake[3][0] == OMOVE){
    cout << "Player O has won!";
    return 0;
  }
  return 2;
}
