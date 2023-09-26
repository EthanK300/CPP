#include <iostream>
#include <cstring>
#include <vector>
#include "Media.h"
#include "Movies.h"
#include "Music.h"
#include "VideoGames.h"

using namespace std;

/*
Author: Ethan K
Classes - add search and delete media

 */
//function prototypes
void ADD(vector<Media*>* database);
void DELETE(vector<Media*>* database);
void SEARCH(vector<Media*>* database);
//main
int main(){
  bool active = true;
  char terminal[80];
  vector<Media*>* database = new vector<Media*>();
  cout << "List of commands: ADD, SEARCH, DELETE, QUIT" << endl;
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
//add object, ask for type and data
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
//delete selected object searching by year or title
void DELETE(vector<Media*>* database){
  bool active = true;
  char terminal[80];
  
  while(active){
    cout << "Search for title or year? (t/y/quit)" << endl;
    cin.clear();
    cin >> terminal;
    for(int i = 0; i < strlen(terminal); i++){
      if(!isalpha(terminal[i])){
        memmove(terminal+i, terminal+1+i, strlen(terminal)-i);
        i--;
      }
    }
    if(!strcmp(terminal, "t")){
      cout << "Enter title: " << endl;
      cin.ignore(10000, '\n');
      cin >> terminal;
      cin.clear();
      for(vector<Media*>::iterator it = database->begin(); it != database->end(); ++it){
	bool found = false;
	if(!strcmp(terminal, (*it)->getTitle())){
	  active = false;
	  found = true;
	  cout << "Confirm? (y/n)" << endl;
	  cin.ignore(10000, '\n');
	  cin >> terminal;
	  if(!strcmp(terminal, "y")){
	    delete *it;
	    database->erase(it);
	    return;
	  }else{
	    return;
	  }
	}
	if(!found){
	  cout << "Bad Input, object does not exist" << endl;
	}
      }
    }else if(!strcmp(terminal, "y")){
      cout << "Enter year:" << endl;
      cin.ignore(10000, '\n');
      cin.clear();
      cin >> terminal;
      for(vector<Media*>::iterator it = database->begin(); it != database->end(); ++it){
	bool found = false;
	if(atoi(terminal) == ((*it)->getYear())){
	  //print out information about each object
	  active = false;
	  found = true;
	  cout << "Confirm? (y/n)" << endl;
	  cin.ignore(10000, '\n');
	  cin >> terminal;
	  if(!strcmp(terminal, "y")){
	    delete *it;
	    database->erase(it);
	    cout << "Deleted object." << endl;
	    return;
	  }else{
	    return;
	  }
	}
	if(!found){
	    cout << "This object does not exist!" << endl;
	}
      }
    }else if(!strcmp(terminal, "quit")){
      cout << "Quitted Search." << endl;
      return;
    }else{
      cout << "Bad input." << endl;
    }
  }
}
//search and print out info for selected object, searching by title or year
void SEARCH(vector<Media*>* database){
  bool active = true;
  char terminal[80];
  
  while(active){
    cout << "Search for title or year? (t/y/quit)" << endl;
    cin.clear();
    cin >> terminal;
    for(int i = 0; i < strlen(terminal); i++){
      if(!isalpha(terminal[i])){
        memmove(terminal+i, terminal+1+i, strlen(terminal)-i);
        i--;
      }
    }
    if(!strcmp(terminal, "t")){
      cout << "Enter title:" << endl;
      cin.ignore(10000, '\n');
      cin.clear();
      cin >> terminal;
      for(vector<Media*>::iterator it = database->begin(); it != database->end(); ++it){
	bool found = false;
	if(!strcmp(terminal, (*it)->getTitle())){
	  //print out information about each object
	  (*it)->getInformation();
	  active = false;
	  found = true;
	}
	if(!found){
	    cout << "This object does not exist!" << endl;
	}
      }
    }else if(!strcmp(terminal, "y")){
      cout << "Enter year:" << endl;
      cin.ignore(10000, '\n');
      cin.clear();
      cin >> terminal;
      for(vector<Media*>::iterator it = database->begin(); it != database->end(); ++it){
	bool found = false;
	if(atoi(terminal) == ((*it)->getYear())){
	  //print out information about each object
	  cout << "Media information: " << endl;
	  (*it)->getInformation();
	  active = false;
	  found = true;
	}
	if(!found){
	    cout << "This object does not exist!" << endl;
	}
      }
    }else if(!strcmp(terminal, "quit")){
      cout << "Quitted Search." << endl;
      return;
    }else{
      cout << "Bad input." << endl;
    }
    
  }
}
