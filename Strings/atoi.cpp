#include <iostream>
#include <climits>
using namespace std;

bool isDigit(char c){
  return c >= '0' && c <= '9';
}

int myAtoi(string s) {
  int i = 0;
  int num = 0;
  int sign = 1;
  
  // 1. Ignore leading whitespace

  while(i < s.length() && s[i] == ' '){
    i++;
  }

  // 2. sign + or -

  if(i < s.length()){
    if(s[i] == '-'){
      sign = -1;
      i++;
    }
    else if(s[i] == '+'){
      i++;
    }
  }

  // 3. conversion

  while (i<s.length() && isDigit(s[i])){
    int digit = s[i] - '0';
    
    // 4. Rounding

    if(num == INT_MAX/10){
      if(sign == 1){
        if(digit >= 7){
          return INT_MAX;
        }
      }
      else if(sign = -1){
        if(digit >= 8){
          return INT_MIN;
        }
      }
    }

    if(num > INT_MAX/10){
      if(sign == 1){
        return INT_MAX;
      }
      else{
        return INT_MIN;
      }
    }

    num = num * 10 + digit;
    i++;
  }
  return sign * num;
}


int main() {

  string s;
  cout << "Enter the string s: ";
  cin >> s;

  cout << myAtoi(s);

 return 0;
}