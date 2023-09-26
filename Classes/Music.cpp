#include <iostream>
#include "Music.h"
#include <cstring>

using namespace std;
//music data inputter
Music::Music() : Media(){
  int durationIN = 0;
  bool active = true;
  bool valid = true;
  
  cout << "Enter artist: " << endl;
  cin.clear();
  cin >> artist;
  cin.ignore(10000, '\n');
  cout << "Enter publisher: " << endl;
  cin.clear();
  cin >> publisher;
  cin.ignore(10000, '\n');

  while(active){
    cout << "Enter the duration of the music: " << endl;
    cin.clear();
    cin >> durationIN;
    if(durationIN == 0){
      valid = false;
    }
    if(valid){
      active = false;
    }else{
      active = true;
      cout << "Bad input" << endl;
    }
  }
  duration = durationIN;
  
}
//return information about music object
void Music::getInformation(){
  cout << "Title: " << title << ", Year: " << year << ", Artist: " << artist << ", Publisher: " << publisher << ", Duration: " << duration << endl;
}
