#include <iostream>

using namespace std;

namespace Color{
  enum Color{
    Red, Black
  };
};

using namespace Color;

int main(){
  Color::Color c = Red;
  if(c == Red){
    cout << " 1" << endl;
  }else{
    cout << "2" << endl;
  }
  
  return 0;
}

