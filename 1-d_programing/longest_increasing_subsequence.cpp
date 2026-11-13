#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int n;
int t[2501][2501];

int solve(vector<int>& nums, int i, int p){
  if(i>=n){
    return 0;
  }

  if(p != -1 && t[i][p] != -1){
    return t[i][p];
  }

  int take = 0;
  if(p == -1 || nums[i] > nums[p]){
    take = 1 + solve(nums, i+1, i);
  }
  
  int skip = solve(nums, i+1, p);
  
  if(p != -1){
    t[i][p] = max(take, skip);
  }

  return max(take, skip);
}

int memorization(vector<int>& nums){
  n = nums.size();
  memset(t, -1, sizeof(t));
  return solve(nums, 0, -1); 
}

int lengthOfLIS(vector<int>& nums) {
  return memorization(nums);        
}

int main() {
  vector<vector<int>> testCases = {
      {10, 9, 2, 5, 3, 7, 101, 18},
      {0, 1, 0, 3, 2, 3},
      {7, 7, 7, 7, 7, 7, 7},
      {},
  };

  for (int i = 0; i < testCases.size(); ++i) {
    cout << "Test case " << i + 1 << ": "
         << lengthOfLIS(testCases[i]) << '\n';
  }

 return 0;
}