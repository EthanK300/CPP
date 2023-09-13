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

void ADD(vector<Student*>* StudentList);
void PRINT(vector<Student*>* StudentList);
void DELETE(vector<Student*>* StudentList);

int main(){
  vector<Student> StudentList;
  char terminal[80];
  bool active = true;
  while(active){
      cout << "Enter a command: " << endl;

      cin.ignore();
      cin.clear();
      cin >> terminal;
    
      for(int i = 0; i < strlen(terminal) - 1; i++){
	if(!isalpha(terminal[i])){
	  memmove(terminal+i, terminal+1+i, strlen(terminal)-i);
	  i--;
	}
      }
      //good command string
      if(terminal == "ADD"){
	ADD(StudentList);
      }else if(terminal == "PRINT"){
	PRINT(StudentList);
      }else if(terminal == "DELETE"){
	DELETE(StudentList);
      }else if(terminal == "QUIT"){
	return 0;
      }else{
	cout << "Bad Input" << endl;
      }
    }
  }
}

void ADD(vector<Student*>* intakeList){
	cout << "Enter student first name: " << endl;
	cin.clear();
	cin.ignore();
	cin >> firstNameIN;
	cout << "Enter student last name: " << endl;
	cin.clear();
	cin.ignore();
	cin >> lastNameIN;
	cout << "Enter student ID: " << endl;
	cin.clear();
	cin.ignore();
	cin >> studentIDIN;
	cout << "Enter student GPA: " << endl;
	cin.clear();
	cin.ignore();
	cin >> gpaIN;
	
  Student* student = new Student();
  student->firstName = firstNameIN;
  student->lastName = lastNameIN;
  student->studentID = studentIDIN;
  student->gpa = gpaIN;
	intakeList.push_back(student);
}

void PRINT(vector<Student*>* intakeList){
  for(vector<Student*> iterator it = StudentList->begin(); it != StudentList->end(); ++it){
    cout << (*it)->firstName  << ", " << (*it)->lastName << ", ID: " << (*it)->studentID << ", GPA: " << (*it)->gpa << endl;
  }
}

void DELETE(vector<Student*>* intakeList){
  int intake = 0;
  for(vector<Student*> iterator it = StudentList->begin(); it != StudentList->end(); ++it){
    cout << it << ". " << (*it)->firstName  << ", " << (*it)->lastName << ", ID: " << (*it)->studentID << ", GPA: " << (*it)->gpa << endl;
  }
  cout << "Select index of student to remove: " << endl;
  cin.ignore();
	cin.clear();
	cin << intake;
	for(vector<Student*> iterator it = StudentList->begin(); it != StudentList->end(); ++it){
		if(intake == it){
			vector.erase(it);
		}
	}
}

