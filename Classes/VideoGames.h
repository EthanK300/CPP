#ifndef VIDOEGAMES
#define VIDOEGAMES
#include <iostream>
#include "Media.h"

class VideoGames : public Media{
public:
  VideoGames();
  int rating = 0;
  char publisher[80];
  void getInformation();
};

#endif
