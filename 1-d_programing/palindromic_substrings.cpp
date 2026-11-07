#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


int t[1001][1001];
bool check(string &s, int i, int j){
  if(i > j){
    return true;
  }

  if(t[i][j] != -1){
    return t[i][j];
  }

  if(s[i] == s[j]){
    return t[i][j] = check(s, i+1, j-1);
  }
  return t[i][j] = false;
}

int memorization(string s){
  int n = s.length();
  int count = 0;
  memset(t, -1, sizeof(t));
  
  for(int i=0; i<n; i++){
    for(int j=i; j<n; j++){

      if(check(s, i, j)){
        count++;
      }

    }
  }
  return count;
}

int bottomUp(string s){
  int n = s.length();
  vector<vector<bool>> t(n, vector<bool>(n, false));
  int count = 0;

  for(int L=1; L<=n; L++){
    for(int i=0; i+L-1<n; i++){
      int j = i + L - 1;
      if(i == j){
        t[i][i] = true;
      }
      else if(i+1 == j){
        t[i][j] = (s[i] == s[j]);
      }
      else{
        t[i][j] = (s[i] == s[j] && t[i+1][j-1]);
      }

      if(t[i][j] == true){
        count++;
      }
    }
  }
  return count;
}

int countSubstrings(string s) {
  // return memorization(s);
  return bottomUp(s);
}

int main() {

  string s;
  cout << "Enter a string: ";
  cin >> s;

  cout << "Number of palindromic substrings: " << countSubstrings(s) << endl;

 return 0;
}