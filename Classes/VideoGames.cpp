#include <iostream>
#include "VideoGames.h"
using namespace std;
//videogames information inputter
VideoGames::VideoGames() : Media(){
  cout << "Enter publisher: " << endl;
  cin.clear();
  cin >> publisher;
  cin.ignore(10000, '\n');
  while(rating == 0){
    cout << "Enter rating, can't be 0: " << endl;
    cin.clear();
    cin >> rating;
    cin.ignore(10000, '\n');
  }
}
//return information about video game object
void VideoGames::getInformation(){
  cout << "Title: " << title << ", Year: " << year << ", Publisher: " << publisher << ", Rating: " << rating << endl;
  return;
}
