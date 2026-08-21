#include <iostream>
#include <vector>
using namespace std;


void solve(string& curr, int& n, vector<string>& result, int open, int close){
  if(curr.length() == 2*n) {
    result.push_back(curr);
    return;
  }
  if (open < n) {
    curr.push_back('(');
    solve(curr, n, result, open + 1, close);
    curr.pop_back();
  }

  if (close < open) {
    curr.push_back(')');
    solve(curr, n, result, open, close + 1);
    curr.pop_back();
  }
}

vector<string> generateParenthesis(int n) {
  vector<string> result;
  string curr = "";
  solve(curr, n, result, 0, 0);
  return result;
}


int main() {

  int n = 3;
  vector<string> parentheses = generateParenthesis(n);
  for(const auto& p : parentheses) {
    cout << p << endl;
  }

 return 0;
}