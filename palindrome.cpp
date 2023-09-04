#include <iostream>
#include <cstring>
using namespace std;

/*
Author: Ethan K
Plaindrome
(yes its a pun, my code is plain)

Palindrome project: intakes a string and returns if it is a palindrome or not.
 */

int main()
{
  char input[80];
  char input2[80];
  char intake[80];
  int num = 0;
  char buffer = 'x';
  cout << "Enter a string:" << endl;
  cin.get(input, 80);
  cin.get();
  strlwr(input);
  for(int i = 0; i < strlen(input) - 1; i++){
    if(isalnum(input[i])){
      //since project permits alnum and alnum permits alphabet and numbers this is ok
    }else{
      memmove(input+i, input+1+i, strlen(input)-i);
      i--;
    }
  }
  //cleaned string copying
  strcpy(intake, input);
  for(int i = 0; i < strlen(intake) -1; i++){
    if(intake[i] == intake[strlen(intake) - 1 - i]){
      //first is equal to last, second is equal to second last, etc
    }else{
      cout << "IS NOT a palindrome";
      return 0;
    }
  }
  cout << "Filtered string: " << intake << endl << "Is a palindrome";
  return 0;
}
