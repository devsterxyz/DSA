#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;

int t[1001][1001];
int isPalindrome(string &s, int i, int j){
  if(i>=j){
    return 1;
  }

  if(t[i][j] != -1){
    return t[i][j];
  }

  if(s[i] == s[j]){
    return t[i][j] = isPalindrome(s, i+1, j-1);
  }

  return t[i][j] = 0;
}

string memorization(string s){
  int n = s.length();
  memset(t, -1, sizeof(t));
  int maxLen = INT_MIN;
  int sp = 0;

  for(int i=0; i<n; i++){
    for(int j=i; j<n; j++){
      if(isPalindrome(s, i, j) == true){
        if(j-i+1 > maxLen){
          maxLen = j-i+1;
          sp = i;
        }
      }
    }
  }

  return s.substr(sp, maxLen);
}

string bottomUp(string s){
  int n = s.length();

  vector<vector<bool>> t(n, vector<bool>(n, false));
  // state: t[i][j] = ture if s[i:j] is palindrome, false if s[i:j] is not a palindrome

  int maxL = 0;
  int idx = 0;

  for(int i=0; i<n; i++){
    t[i][i] = true;
    maxL = 1;
  }

  for(int L=2; L<=n; L++){
    for(int i=0; i<n-L+1; i++){
      int j = i+L-1;

      if(s[i] == s[j] && L==2){
        t[i][j] = true;
        if(L > maxL){
          maxL = L;
          idx = i;
        }
      }
      else if(s[i] == s[j] && t[i+1][j-1] == true){
        t[i][j] = true;
        if(L > maxL){
          maxL = L;
          idx = i;
        }
      }
    }
  }

  return s.substr(idx, maxL);
}

string longestPalindrome(string s) {
  // return memorization(s);
  return bottomUp(s);
}

int main() {

  string s;
  cout << "Enter the string: ";
  cin >> s;
  cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;

 return 0;
}