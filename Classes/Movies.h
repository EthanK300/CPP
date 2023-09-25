#ifndef MOVIES
#define MOVIES
#include <iostream>
#include "Media.h"

class Movies : public Media{
public:
  Movies();
  char director[80];
  int duration = 0;
  int rating = 0;
  void getInformation();
};

#endif
