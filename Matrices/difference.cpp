#include <iostream>

using namespace std;

int main(){
  
  int m1[2][2] = {
    {1,2},
    {3,4}
  };

  int m2[2][2] = {
    {5,6},
    {7,8}
  };

  int r1[2][2] = {
    {0,0},
    {0,0}
  };

  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      r1[i][j] = m1[i][j] - m2[i][j];
    }
  }

  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      cout << r1[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}