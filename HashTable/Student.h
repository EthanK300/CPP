#ifndef STUDENT
#define STUDENT
#include <iostream>
#include <cstring>

using namespace std;

class Student{
public:
  Student();
  char* getFirstName();
  char* getLastName();
  int getStudentID();
  float getGPA();
  void printInfo();
protected:
  char firstName[80];
  char lastName[80];
  int studentID = 0;
  float GPA = 0;
};

#endif
