#include <iostream>
using namespace std;
int main()
{
  int var = 0;
  int* varPtr = &var;
  cout << var << endl;
  *varPtr = 1;
  cout << var << endl;
  
  
  return 0;
}

