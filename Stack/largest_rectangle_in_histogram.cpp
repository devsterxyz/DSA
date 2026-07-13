#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int largestRectangleArea(vector<int>& heights) {
  int n = heights.size();
  stack<int> st;
  int maxArea = 0;

  for(int i=0; i<n; i++){
    while(!st.empty() && heights[st.top()] > heights[i]){
      int ele = st.top();
      st.pop();
      int nse = i;
      int pse = st.empty() ? -1 : st.top();
      maxArea = max(maxArea, heights[ele] * (nse - pse - 1));
    }
    st.push(i);
  }

  while(!st.empty()){
    int nse = n;
    int ele = st.top();
    st.pop();
    int pse = st.empty() ? -1 : st.top();
    maxArea = max(maxArea, heights[ele] * (nse - pse - 1));
  }
  return maxArea;
}


int main() {

  int n;
  cout << "Enter the number of bars in the histogram: ";
  cin >> n;

  vector<int> heights(n);
  cout << "Enter the heights of the bars:" << endl;
  for(int i = 0; i < n; i++) {
    cin >> heights[i];
  }

  int maxArea = largestRectangleArea(heights);
  cout << "The area of the largest rectangle in the histogram is: " << maxArea << endl;

 return 0;
}