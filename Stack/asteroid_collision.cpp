#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<int> asteroidCollision(vector<int>& asteroids) {
  stack<int> st;
  vector<int> ans;
  for(int i=0; i<asteroids.size(); i++){
    bool flag = false;
    while(!st.empty() && asteroids[i] < 0){
      int k = -asteroids[i];
      int prev = st.top();
      if(prev < 0){
        break;
      }
      else if(prev > k){
        flag = true;
        break;
      }
      else if(prev < k){
        st.pop();
      }
      else{
        flag = true;
        st.pop();
        break;
      }
    }
    if(!flag){
      st.push(asteroids[i]);
    }
  }
  while(!st.empty()){
    int n = st.top();
    st.pop();
    ans.insert(ans.begin(), n);
  }
  return ans;
}


int main() {

  int n;
  cout << "Enter the number of asteroids: ";
  cin >> n;

  vector<int> asteroids(n);
  cout << "Enter the sizes of the asteroids (positive for right-moving, negative for left-moving):" << endl;
  for(int i = 0; i < n; i++) {
    cin >> asteroids[i];
  }

  vector<int> result = asteroidCollision(asteroids);
  
  cout << "Remaining asteroids after all collisions: ";
  for(int size : result) {
    cout << size << " ";
  }
  cout << endl;

 return 0;
}