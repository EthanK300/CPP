#ifndef MEDIA
#define MEDIA

#include <iostream>
using namespace std;

class Media{
public:
  Media();
  char getTitle();
  int getYear();
protected:
  int id;
  int year;
  char title[80];
};

#endif
