#include <iostream>
using namespace std;

/*
Author: Ethan Kusse
8/31/2023

Guessing game: pick a number and it tells you if you are too high or too low, then asks if you want to play again when you win.

 */

int main(){
  srand(time(NULL));
  int number = 0;
  int guess = 0;
  int numGuesses = 0;
  char playAgain = 'y';
  while(playAgain == 'y'){
    number = rand();
    number %= 100;
    while (guess != number) {
      cin.clear();
      cin.ignore();
      cin >> guess;
      if(guess < number){
	cout << "You were too low! Try Again" << endl;
	numGuesses++;
      }else if(guess > number){
	cout << "You were too high! Try Again" << endl;
	numGuesses++;
      }else if(guess != number){
	cout << "You guessed something else that maybe wasn't a number..." << endl;
      }
    }
    cout << "You were correct! it took " << numGuesses <<" guesses!";
    cin.clear();
    cin.ignore();
    cout << "Play Again? y/n" << endl;
    cin >> playAgain;
  }
  return 0;
}
