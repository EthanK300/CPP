#ifndef MOVIES
#define MOVIES
#include <iostream>
#include "Media.h"
//movies class structual data
class Movies : public Media{
public:
  Movies();
  char director[80];
  int duration = 0;
  int rating = 0;
  void getInformation();
};

#endif
