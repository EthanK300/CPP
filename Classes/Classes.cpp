#include <iostream>
#include <cstring>
#include <vector>
#include "Media.h"
#include "Movies.h"
#include "Music.h"
#include "VideoGames.h"

using namespace std;

void ADD(vector<Media*>* database);
void DELETE(vector<Media*>* database);
void SEARCH(vector<Media*>* database);

int main(){
  bool active = true;
  char terminal[80];
  vector<Media*>* database = new vector<Media*>();
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
      ADD(database);
    }else if(!strcmp(terminal, "DELETE")){
      DELETE(database);
    }else if(!strcmp(terminal, "SEARCH")){
      SEARCH(database);
    }else if(!strcmp(terminal, "QUIT")){
      return 0;
    }else{
      cout << "Bad Input" << endl;
    }
  }
}

void ADD(vector<Media*>* database){
  char terminal[80];
  bool active = true;
  while(active){
    cout << "What would you like to add? There are MOVIES, MUSIC, and VIDOEGAMES." << endl;
    cin.clear();
    cin >> terminal;
    for(int i = 0; i < strlen(terminal); i++){
      if(!isalpha(terminal[i])){
	memmove(terminal+i, terminal+1+i, strlen(terminal)-i);
	i--;
      }
    }
    //good command string
    if(!strcmp(terminal, "MOVIES")){
      Movies* movie = new Movies();
      database->push_back(movie);
      active = false;
    }else if(!strcmp(terminal, "MUSIC")){
      Music* music = new Music();
      database->push_back(music);
      active = false;
    }else if(!strcmp(terminal, "VIDOEGAMES")){
      VideoGames* videogames = new VideoGames();
      database->push_back(videogames);
      active = false;
    }else{
      cout << "Bad Input" << endl;
    }
  }
}

void DELETE(vector<Media*>* database){

}

void SEARCH(vector<Media*>* database){

}
