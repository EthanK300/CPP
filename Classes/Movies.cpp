#include <iostream>
#include "Movies.h"
using namespace std;

Movies::Movies() : Media(){
  cout << "Enter director name: " << endl;
  cin.clear();
  cin >> director;
  cin.ignore(10000, '\n');
  while(duration == 0){
    cout << "Enter duration: " << endl;
    cin.clear();
    cin >> duration;
    cin.ignore(10000, '\n');
  }
  while(rating == 0){
    cout << "Enter rating, can't be 0: " << endl;
    cin.clear();
    cin >> rating;
    cin.ignore(10000, '\n');
  }
}

void Movies::getInformation(){
  cout << "Title: " << title << ", Year: " << year << ", Director: " << director << ", Duration: " << duration << ", Rating: " << rating << endl;
  return;
}
