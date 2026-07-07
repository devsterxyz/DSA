#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
  int n = temperatures.size();
  vector<int> ans(n, 0);
  stack<pair<int, int>> st;
  for(int i=0; i<n; i++){
    while(!st.empty() && temperatures[i] > st.top().first){
      int stackT = st.top().first;
      int stackInd = st.top().second;
      st.pop();
      ans[stackInd] = (i - stackInd);
    }
    st.push({temperatures[i], i});
  }
  return ans;
}

int main() {

  int n;
  cout << "Enter the number of days: ";
  cin >> n;
  vector<int> temperatures(n);
  cout << "Enter the temperatures for each day: ";
  for(int i=0; i<n; i++){
    cin >> temperatures[i];
  }
  vector<int> result = dailyTemperatures(temperatures);
  cout << "Days until a warmer temperature: ";
  for(int i=0; i<n; i++){
    cout << result[i] << " ";
  }
  cout << endl;

 return 0;
}