#include <iostream>
#include <vector>
#include <numeric>
#include <cstring>
using namespace std;

int t[201][20001];
bool solve(vector<int>& nums, int i, int x){
  if(x == 0){
    return true;
  }

  if(i >= nums.size()){
    return false;
  }

  if(t[i][x] != -1){
    return t[i][x];
  }

  bool take = false;
  if(nums[i] <= x){
    take = solve(nums, i+1, x-nums[i]);
  }
  bool not_take = solve(nums, i+1, x);

  return t[i][x] = take || not_take;
}

bool memorization(vector<int>& nums){
  int n = nums.size();
  int sum = accumulate(begin(nums), end(nums), 0);
  
  if(sum%2 != 0){
    return false;
  }
  memset(t, -1, sizeof(t));

  int x = sum/2;

  return solve(nums, 0, x);
}

bool canPartition(vector<int>& nums) {
  return memorization(nums);      
}

int main() {
    vector<vector<int>> tests = {
        {1, 5, 11, 5},
        {1, 2, 3, 5},
        {1, 2, 5},
        {1, 2, 3, 4, 5}
    };

    for (auto &nums : tests) {
        cout << boolalpha << canPartition(nums) << endl;
    }

    return 0;
}