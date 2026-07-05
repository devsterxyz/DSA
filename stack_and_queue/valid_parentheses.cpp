#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
  stack<char> st;
  int n = s.size();
  for(int i=0; i<n; i++){
    if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
      st.push(s[i]);
    }
    else{
      if(st.empty()){
        return false;
      }
      else{
        char ch = st.top();
        st.pop();
        if((s[i] == ')' && ch == '(') || (s[i] == ']' && ch == '[') || (s[i] == '}' && ch == '{')){

        }
        else{
          return false;
        }
      }
    }
  }
  return st.empty();
}

int main() {

  string s;
  cout << "Enter a string of parentheses: ";
  cin >> s;

  if(isValid(s)){
    cout << "Valid parentheses" << endl;
  }
  else{
    cout << "Invalid parentheses" << endl;
  }

 return 0;
}