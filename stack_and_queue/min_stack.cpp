#include <iostream>
#include <stack>
using namespace std;

class MinStack {
  stack<pair<int, int>> st;
public:
  MinStack() {
      
  }
  
  void push(int value) {
    if(st.empty()){
      st.push({value, value});
    }
    else{
      st.push({value, min(value, st.top().second)});
    }
  }
  
  void pop() {
    st.pop();
  }
  
  int top() {
    return st.top().first;
  }
  
  int getMin() {
    return st.top().second;
  }
};


int main() {

 return 0;
}