#include <iostream>
using namespace std;
int main()
{
  char input[] = "hellothere12345";
  memmove(input, input+1, strlen(input));
  cout << input;

  
  return 0;
}

