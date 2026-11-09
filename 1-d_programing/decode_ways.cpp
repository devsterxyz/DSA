#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


int t[101];
int solve(int i, string &s, int &n){
  if(t[i] != -1){
    return t[i];
  }

  if(i == n){
    return t[i] = 1;
  }

  if(s[i] == '0'){
    return t[i] = 0;
  }

  int result = solve(i+1, s, n);


    if(i+1 < n && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))){
      result += solve(i+2, s, n);
    }

  return t[i] = result;

}

int memorization(string s){
  int n = s.length();
  memset(t, -1, sizeof(t));
  return solve(0, s, n);
}

int bottomUP(string s){
  int n = s.length();
  vector<int> t(n+1, 0);
  //t[i] = number of ways to decode string s from index i to n
  t[n] = 1;
  for(int i=n-1; i>=0; i++){
    if(s[i] == 0){
      t[i] = 0;
    }
    else{
      t[i] = t[i+1];

      if(i<n-1){
        if(s[i] == '1' || (s[i] == '2' && s[i+2] <= '6')){
          t[i] += t[i+2];
        }
      }
    }
  }
  return t[0];
}

int numDecodings(string s) {
  // return memorization(s);
  return bottomUP(s);
}

int main() {

  string s;
  cout << "Enter the string: ";
  cin >> s;

  cout << numDecodings(s);

 return 0;
}