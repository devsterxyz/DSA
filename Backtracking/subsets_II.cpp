#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findSubsets(int idx, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
  ans.push_back(temp);
  for(int i=idx; i<nums.size(); i++){
    if(i!=idx && nums[i] == nums[i-1]){
      continue;
    }
    temp.push_back(nums[i]);
    findSubsets(i+1, nums, temp, ans);
    temp.pop_back();
  }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  vector<vector<int>> ans;
  vector<int> temp;
  sort(nums.begin(), nums.end());
  findSubsets(0, nums, temp, ans);
  return ans;
}

int main() {

  vector<int> nums = {1, 2, 2};
    vector<vector<int>> subsets = subsetsWithDup(nums);
    for(const auto& subset : subsets) {
      cout << "[";
      for(int i = 0; i < subset.size(); i++) {
        cout << subset[i];
        if(i < subset.size() - 1) {
          cout << ", ";
        }
      }
      cout << "]" << endl;
    }

 return 0;
}