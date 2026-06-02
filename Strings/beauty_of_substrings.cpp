#include <iostream>
#include <vector>
using namespace std;

int beauty(vector<int> &alpha){
  int mf = 0;
  int lf = 1e9;
  for(int i=0; i<26; i++){
    mf = max(mf, alpha[i]);
    if(alpha[i]>=1){
      lf = min(lf, alpha[i]); 
    }
  }
  return mf-lf;
}

int beautySum(string s) {
  int res = 0;
  for(int i=0; i<s.size(); i++){
    vector<int>alpha(26, 0);
    for(int j=i; j<s.size(); j++){
      alpha[s[j] - 'a']++;
      res = res + beauty(alpha);
    }
  }
  return res;
}

int main() {

  string s;
  cout << "Enter the string: ";
  cin >> s;

  cout << beautySum(s) << endl;

 return 0;
}