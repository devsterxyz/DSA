#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int characterReplacement(string s, int k) {
  int l = 0;
  int r = 0;
  int maxLen = 0;
  int maxF = 0;
  vector<int> hash(26, 0);
  while(r < s.size()){
    hash[s[r] - 'A']++;
    maxF = max(maxF, hash[s[r] - 'A']);

    if((r-l+1) - maxF > k){
      hash[s[l] - 'A']--;
      l++;
    }
    if((r-l+1) - maxF <= k){
      maxLen = max(maxLen, r-l+1);
    }
    r++;
  }
  return maxLen;
}

int main() {

  string s;
  int k;
  cout << "Enter a string: ";
  cin >> s;
  cout << "Enter the value of k: ";
  cin >> k;
  int length = characterReplacement(s, k);
  cout << "Length of longest substring after replacement: " << length << endl;

 return 0;
}