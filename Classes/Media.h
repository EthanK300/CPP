#ifndef MEDIA
#define

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
  char[80] title;
};

#endif
