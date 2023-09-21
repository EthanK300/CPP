#include <iostream>
#include "Media.h"
#include <cstring>
using namespace std;

Media(){
  char yearIN[80];
  active = true;
  valid = true ;
  cout << "Enter title of media: " << endl;
  cin.clear();
  cin >> title;
  cin.ignore();

  while(active){
    cout << "Enter year media was released: " << endl;
    cin.clear();
    cin >> yearIN;
    for(int i = 0; i < strlen(yearIN - 1); i++){
      if(!isdigit(yearIN[i])){
	valid = false
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

char* Media::getTitle(){
  return title;
}

char* Media::getYear(){
  return year;
}
