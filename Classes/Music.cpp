#include <iostream>
#include "Music.h"
#include <cstring>

using namespace std;

Music::Music() : Media(){
  char durationIN[80];
  active = true;
  valid = true;
  
  cout << "Enter artist: " << endl;
  cin.clear();
  cin >> artist;
  cin.ignore();
  cout << "Enter publisher: " << endl;
  cin.clear();
  cin >> publisher;
  cin.ignore();

  while(active){
    cout << "Enter the duration of the music: " << endl;
    cin.clear();
    cin >> durationIN;
    for(int i = 0; i < strlen(durationIN - 1); i++){
      if(!isdigit(yearIN[i])){
	valid = false;
      }
    }
    if(valid){
      active = false;
    }else{
      active = true;
      cout << "Bad input" << endl;
    }
  }
  strcpy(title, yearIN);
  
}

char* Music::getInformation(){
  cout << "Title: " << title << endl << "Year: " << year << endl << "Artist: " << artist << endl << "Publisher: " << publisher << endl << "Duration: " << duration << endl;
}
