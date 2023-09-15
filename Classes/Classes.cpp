#include <iostream>
#include <vector>
#include "Media.h"
#include "Movies.h"
#include "Music.h"
#include "VideoGames.h"

using namespace std;

int main(){
  bool active = true;
  char terminal[80];
  vector<Media>;
  while(active){
    cout << "Enter a command: " << endl;
    cin.clear();
    cin >> terminal;
    for(int i = 0; i < strlen(terminal); i++){
      if(!isalpha(terminal[i])){
	memmove(terminal+i, terminal+1+i, strlen(terminal)-i);
	i--;
      }
    }
    //good command string
    if(!strcmp(terminal, "ADD")){
      ADD(StudentList);
    }else if(!strcmp(terminal, "PRINT")){
      PRINT(StudentList);
    }else if(!strcmp(terminal, "DELETE")){
      DELETE(StudentList);
    }else if(!strcmp(terminal, "QUIT")){
      return 0;
    }else{
      cout << "Bad Input" << endl;
    }
  }
}

}
