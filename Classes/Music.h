#ifndef MUSIC
#define MUSIC
#include <iostream>
#include "Media.h"

class Music : public Media{
public:
  Music();
  char artist[80];
  int duration = 0;
  char publisher[80];
  void getInformation();
};

#endif
