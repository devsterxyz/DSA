#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstring>
using namespace std;

unordered_set<string> st;
int n;
int t[301];

bool solve(int idx, string &s){
  if(idx >=n){
    return true;
  }

  if(t[idx] != -1){
    return t[idx];
  }

  if(st.find(s) != st.end()){
    return true;
  }

  for(int l=1; l<=n; l++){
    string temp = s.substr(idx, l);
    if(st.find(temp) != st.end() && solve(idx +l, s)){
      return t[idx] = true;
    }
  } 
  return t[idx] = false;
}

bool memorization(string s, vector<string>& wordDict){
  n = s.length();
  memset(t, -1, sizeof(t));
  for(string &word: wordDict){
    st.insert(word);
  }

  return solve(0, s);
}

bool wordBreak(string s, vector<string>& wordDict) {
  return memorization(s, wordDict);
}

int main() {
  vector<vector<string>> testCases = {
      {"leet", "code"},
      {"apple", "pen"},
      {"cats", "dog", "sand", "and", "cat"},
      {"aaaa", "aaa"},
      {"car", "ca", "rs"}
  };

  vector<string> testStrings = {
      "leetcode",
      "applepenapple",
      "catsandog",
      "aaaaaaa",
      "cars"
  };

  vector<bool> expected = {true, true, false, true, true};

  for (int i = 0; i < testStrings.size(); i++) {
    st.clear();
    bool result = wordBreak(testStrings[i], testCases[i]);
    cout << "Test case " << i + 1 << ": " << (result ? "true" : "false")
         << " | Expected: " << (expected[i] ? "true" : "false") << endl;
  }

  return 0;
}