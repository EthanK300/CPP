#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

/*
Author: Ethan K
 */

struct Student {
  char firstName[80];
  char lastName[80];
  int studentID = 0;
  float gpa = 0;
};

//predefined functions
void ADD(vector<Student*>* StudentList);
void PRINT(vector<Student*>* StudentList);
void DELETE(vector<Student*>* StudentList);

int main(){
  vector<Student*>* StudentList = new vector<Student*>();
  char terminal[80];
  bool active = true;
  //main running loop
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
      ADD(StudentList);
    }else if(!strcmp(terminal, "PRINT")){
      PRINT(StudentList);
    }else if(!strcmp(terminal, "DELETE")){
      DELETE(StudentList);
    }else if(!strcmp(terminal, "QUIT")){
      return 0;
    }else{
      cout << "Bad Input" << endl;
    }
  }
}
//add function - gets all of the data then adds it to the vector of students
void ADD(vector<Student*>* intakeList){
  char firstNameIN[80];
  char lastNameIN[80];
  int studentIDIN = 0;
  float gpaIN = 0;
  
  cout << "Enter student first name: " << endl;
  cin.clear();
  cin >> firstNameIN;
  cin.ignore();
  cout << "Enter student last name: " << endl;
  cin.clear();
  cin >> lastNameIN;
  cin.ignore();
  cout << "Enter student ID: " << endl;
  cin.clear();
  cin >> studentIDIN;
  cin.ignore();
  cout << "Enter student GPA: " << endl;
  cin.clear();
  cin >> gpaIN;
  cin.ignore();
  
  Student* student = new Student();
  strcpy(student->firstName, firstNameIN);
  strcpy(student->lastName, lastNameIN);
  student->studentID = studentIDIN;
  student->gpa = gpaIN;
  intakeList->push_back(student);
}
//print function - prints all students listed in the vector, and "no students" if there are none
void PRINT(vector<Student*>* intakeList){
  cout << "Students: " << endl;
  for(vector<Student*>::iterator it = intakeList->begin(); it != intakeList->end(); ++it){
    cout << (*it)->firstName  << ", " << (*it)->lastName << ", ID: " << (*it)->studentID << ", GPA: " << (*it)->gpa << endl;
  }
  if(intakeList->empty()){
    cout << "No students." << endl;
  }
}
//removes a student using ID number for selection
void DELETE(vector<Student*>* intakeList){
  int intake = 0;
  PRINT(intakeList);
  cout << "Enter student ID of student to remove: " << endl;
  cin.ignore();
  cin.clear();
  cin >> intake;
  for(vector<Student*>::iterator it = intakeList->begin(); it != intakeList->end(); ++it){
    if((*it)->studentID == intake){
      intakeList->erase(it);
      break;
    }
  }
  PRINT(intakeList);
  
}
