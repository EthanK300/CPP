#include <iostream>
#include "Movies.h"
using namespace std;

Movies::Media() : Media(){
  cout << "Enter director name: " << endl;
  cin.clear();
  cin >> director;
  cin.ignore();
  while(duration == 0){
    cout << "Enter duration: " << endl;
    cin.clear();
    cin >> duration;
    cin.ignore();
  }
  while(rating == 0){
    cout << "Enter rating, can't be 0: " << endl;
    cin.clear();
    cin >> rating;
    cin.ignore();
  }
}
