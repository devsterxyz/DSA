#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int t[46];

int solve(int n){

  if(n < 0){
      return 0;
  }

  if(t[n] != -1){
      return t[n];
  }
  
  if(n == 0){
      return 1;
  }

  int one_step = solve(n-1);
  int two_step = solve(n-2);

  return t[n] = one_step + two_step;
}

int solve2(int n){

  if(n == 1 | n == 2){
    return n;
  }

  int a = 1;
  int b = 2;
  int c = 3;
  
  for(int i = 3; i <= n; i++){
    c = b + a;

    a = b;
    b = c;
  }

  return c;
}

int climbStairs(int n) {
  memset(t, -1, sizeof(t));
  // return solve(n);
  return solve2(n);
}


int main() {

  int n;
  cout << "Enter the number of stairs: ";
  cin >> n;

  cout << climbStairs(n);

 return 0;
}