#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs){
  int n = strs.size();
  vector<vector<string>> ans;
  unordered_map<string, vector<string>> mpp;
  for(int i=0; i<n; i++){
    string temp = strs[i];
    sort(begin(temp), end(temp));
    mpp[temp].push_back(strs[i]);
  }

  for(auto it: mpp){
    ans.push_back(it.second);
  }
  return ans;
}


int main(){

  int n;
  cout << "Enter number of strings: ";
  cin >> n;

  vector<string> strs(n);

  cout << "Enter the strings:\n";
  for (int i = 0; i < n; i++) {
    cin >> strs[i];
  }

  vector<vector<string>> result = groupAnagrams(strs);

  cout << "\nGrouped Anagrams:\n";
  for (const auto &group : result){
    cout << "[ ";
    for (const auto &word : group){
      cout << word << " ";
    }
    cout << "]\n";
  }

 return 0;
}