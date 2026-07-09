#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int Operate(int a, int b, string token){
  if(token == "+"){
    return a+b;
  }
  if(token == "-"){
    return a-b;
  }
  if(token == "*"){
    return (long)a*(long)b;
  }
  if(token == "/"){
    return a/b;
  }

  return -1;
}

int evalRPN(vector<string>& tokens) {
  stack<int> st;
  for(string &token: tokens){
    if(token == "+" || token == "-" || token == "*" || token == "/"){
      int b = st.top();
      st.pop();
      int a = st.top();
      st.pop();
      int result = Operate(a, b, token);
      st.push(result);
    }
    else{
      st.push(stoi(token));
    }
  }
  return st.top();
}


int main() {

  vector<string> tokens1 = {"2", "1", "+", "3", "*"};
  cout << "Result 1: " << evalRPN(tokens1) << endl;


  vector<string> tokens2 = {"4", "13", "5", "/", "+"};
  cout << "Result 2: " << evalRPN(tokens2) << endl;

  vector<string> tokens3 = {
    "10", "6", "9", "3", "+", "-11", "*",
    "/", "*", "17", "+", "5", "+"
  };
  cout << "Result 3: " << evalRPN(tokens3) << endl;


 return 0;
}