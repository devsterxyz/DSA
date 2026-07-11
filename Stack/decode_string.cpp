#include <iostream>
#include <stack>
using namespace std;


string decodeString(string s) {
  stack<int> stnum;
  stack<string> ststr;
  string ans = "";
  for(int i=0; i<s.size(); i++){
    char ss = s[i];
    if(ss == ']'){
      string temp = "";
      while(!ststr.empty()){
        string k = ststr.top();
        if(k == "["){
          ststr.pop();
          break;
        }
        temp = k + temp;
        ststr.pop();
      }
      int itra =  stnum.top();
      stnum.pop();
      string original = temp;
      temp = "";
      for(int j=0; j<itra; j++){
        temp += original;
      }
      ststr.push(temp);
      continue;
    }
    if(isdigit(ss)){
      int num = 0;
      while (i < s.size() && isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');
        i++;
      }
      stnum.push(num);
      i--;
    }
    else{
      string str(1, ss);
      ststr.push(str);
    }
  }
  while(!ststr.empty()){
    ans = ststr.top() + ans;
    ststr.pop();
  }
  return ans;
}


int main() {

  string s;
  cout << "Enter the encoded string: ";
  cin >> s;

  string decodedString = decodeString(s);
  cout << "Decoded string: " << decodedString << endl;

 return 0;
}