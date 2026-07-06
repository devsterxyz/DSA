#include <iostream>
#include <vector>
using namespace std;


int lengthOfLongestSubstring(string s) {
  vector<int> hash(256, -1);
  int left = 0;
  int right = 0;
  int maxLen = 0;
  int n = s.size();
  while(right < n){
    if(hash[s[right]] != -1){
      if(hash[s[right]] >= left){
        left = hash[s[right]] + 1;
      }
    }
    int length = right - left + 1;
    maxLen = max(length, maxLen);
    hash[s[right]] = right;
    right++;
  }
  return maxLen;
}

int main() {

  string s;
  cout << "Enter a string: ";
  cin >> s;
  int length = lengthOfLongestSubstring(s);
  cout << "Length of longest substring without repeating characters: " << length << endl;

 return 0;
}