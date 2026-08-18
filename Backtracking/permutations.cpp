#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


int n;
vector<vector<int>> result;
unordered_set<int> st;

void solve(vector<int>& temp, vector<int>& nums){
  if(temp.size() == n){
    result.push_back(temp);
    return;
  }
  
  for(int i=0; i<n; i++){
    if(st.find(nums[i]) == st.end()){
      temp.push_back(nums[i]);
      st.insert(nums[i]);
      solve(temp, nums);
      temp.pop_back();
      st.erase(nums[i]);
    }
  }
}

vector<vector<int>> permute(vector<int>& nums) {
  n = nums.size();
  vector<int> temp;
  solve(temp, nums);
  return result;
}


int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = permute(nums);
    for(const auto& perm : permutations) {
      for(int num : perm) {
        cout << num << " ";
      }
      cout << endl;
    }
    return 0;
}