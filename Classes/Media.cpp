#include <iostream>
#include "Media.h"
#include <cstring>
using namespace std;

Media::Media(){
  bool active = true;
  bool valid = true ;
  cout << "Enter title of media: " << endl;
  cin.clear();
  cin >> title;
  cin.ignore(10000, '\n');

  while(active){
    cout << "Enter year media was released: " << endl;
    cin.clear();
    cin >> year;
    if(year == 0){
      active = true;
      cout << "Bad input" << endl;
    }else{
      active = false;
    }
  }
}

char* Media::getTitle(){
  return title;
}

int Media::getYear(){
  return year;
}

void Media::getInformation(){
  return;
}
