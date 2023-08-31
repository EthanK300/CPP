#include <iostream>
using namespace std;
int number = 0;
int guess = 0;
int numGuesses = 0;
int main(){
  srand(time(NULL));
  number = rand();
  while (guess != number) {
    cin >> guess;
    if(guess < number){
      cout << "You were too low! Try Again";
      numGuesses++;
    }else if(guess > number){
      cout << "You were too high! Try Again";
      numGuesses++;
    }else{
      cout << "You guessed something else that maybe wasn't a number...";
    }
  }
  cout << "You were correct! it took " << numGuesses <<" guesses!";
}
