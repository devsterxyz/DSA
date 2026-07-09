#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int calPoints(vector<string>& operations) {
  stack<int> st;
  for(int i=0; i<operations.size(); i++){
    string s = operations[i];
    if(s == "+"){
      int temp = st.top();
      int first = temp;
      st.pop();
      int second = st.top();
      st.push(temp);
      st.push(first + second);
    }
    else if(s == "D"){
      st.push(st.top()*2);
    }
    else if(s == "C"){
      st.pop();
    }
    else{
      st.push(stoi(s));
    }
  }
  int ans = 0;
  while(!st.empty()){
    ans += st.top();
    st.pop();
  }
  return ans;
}

int main() {

  int n;
  cout << "Enter the number of operations: ";
  cin >> n;

  vector<string> operations(n);
  cout << "Enter the operations (one per line):" << endl;
  for(int i = 0; i < n; i++) {
    cin >> operations[i];
  }

  int totalPoints = calPoints(operations);
  cout << "Total points after all operations: " << totalPoints << endl;

 return 0;
}