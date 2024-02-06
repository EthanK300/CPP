#include <iostream>
#include "Student.h"
#include <cstring>

using namespace std;

Student::Student(int t){
  
}

Student::Student(char* first, char* last, int id){
  srand(time(NULL));
  strcpy(firstName, first);
  strcpy(lastName, last);
  studentID = id;
  GPA = rand();
}

Student::Student(){
  cout << "Input first name: " << endl;
  cin.clear();
  cin >> firstName;
  cout << "Input last name: " << endl;
  cin.clear();
  cin >> lastName;
  cout << "Input student ID: " << endl;
  cin.clear();
  cin >> studentID;
  cout << "Input student's GPA: " << endl;
  cin.clear();
  cin >> GPA;
  cout << "Added student" << endl;
  cin.clear();
}

char* Student::getFirstName(){
  return firstName;
}

char* Student::getLastName(){
  return lastName;
}

int Student::getStudentID(){
  return studentID;
}

float Student::getGPA(){
  return GPA;
}

void Student::printInfo(){
  cout << "Student Name: " << firstName << " " << lastName << ", ID: " << studentID << ", GPA: " << GPA << endl;
  return;
}
