#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TrieNode{
  TrieNode *children[26];
  bool isEndOfWord;
  TrieNode(){
    isEndOfWord = false;
    for (int i = 0; i < 26; i++){
      children[i] = nullptr;
    }
  }
};

TrieNode *root;

TrieNode *getNode(){
  return new TrieNode();
}

void insert(string &word){
  TrieNode *curr = root;
  for (char ch : word){
    int idx = ch - 'a';
    if (curr->children[idx] == nullptr){
      curr->children[idx] = getNode();
    }
    curr = curr->children[idx];
  }
  curr->isEndOfWord = true;
}

int dfs(int i, string &s, vector<int> &dp){
  int n = s.size();
  if (i == n){
    return 0;
  }
  if (dp[i] != -1){
    return dp[i];
  }
  int ans = 1 + dfs(i + 1, s, dp);
  TrieNode *curr = root;
  for (int j = i; j < n; j++){
    int idx = s[j] - 'a';
    if (curr->children[idx] == nullptr){
      break;
    }
    curr = curr->children[idx];
    if (curr->isEndOfWord){
      ans = min(ans, dfs(j + 1, s, dp));
    }
  }
  return dp[i] = ans;
}

int minExtraChar(string s, vector<string> &dictionary){
  root = getNode();
  for (string &word : dictionary){
    insert(word);
  }
  vector<int> dp(s.size(), -1);

  return dfs(0, s, dp);
}

int main(){
  // Test case 1
  string s1 = "leetscode";
  vector<string> dict1 = {"leet", "code", "leetcode"};
  cout << "Test 1: " << minExtraChar(s1, dict1) << " (Expected: 1)" << endl;

  // Test case 2
  string s2 = "sayhelloworld";
  vector<string> dict2 = {"say", "hello", "world"};
  cout << "Test 2: " << minExtraChar(s2, dict2) << " (Expected: 3)" << endl;

  // Test case 3
  string s3 = "abcdefghij";
  vector<string> dict3 = {"abc", "def", "ghi"};
  cout << "Test 3: " << minExtraChar(s3, dict3) << " (Expected: 1)" << endl;

  // Test case 4
  string s4 = "a";
  vector<string> dict4 = {"a"};
  cout << "Test 4: " << minExtraChar(s4, dict4) << " (Expected: 0)" << endl;

  // Test case 5
  string s5 = "xyz";
  vector<string> dict5 = {"abc", "def"};
  cout << "Test 5: " << minExtraChar(s5, dict5) << " (Expected: 3)" << endl;

  return 0;
}