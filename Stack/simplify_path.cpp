#include <iostream>
#include <stack>
#include <sstream>
using namespace std;


string simplifyPath(string path) {
  stack<string> st;
  string token = "";
  stringstream ss(path);

  while(getline(ss, token, '/')){
    if(token == "" || token == "."){
      continue;
    }
    if(token != ".."){
      st.push(token);
    }
    else if(!st.empty()){
      st.pop();
      }
  }

  if(st.empty()){
    return "/";
  }

  string ans = "";
  while(!st.empty()){
    ans = "/" + st.top() + ans;
    st.pop();
  }
  return ans;
}


int main() {

  string path;
  cout << "Enter the path to simplify: ";
  cin >> path;

  string simplifiedPath = simplifyPath(path);
  cout << "Simplified path: " << simplifiedPath << endl;

 return 0;
}