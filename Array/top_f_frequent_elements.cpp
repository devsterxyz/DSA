#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
  int n = nums.size();
  unordered_map<int, int> mpp;
  for(int& num: nums){
    mpp[num]++;
  }

  vector<vector<int>> bucket(n+1);
  for(auto &it: mpp){
    int ele = it.first;
    int freq = it.second;

    bucket[freq].push_back(ele);
  }

  vector<int> ans;

  for(int i=n; i>=0; i--){
    if(bucket[i].size() == 0){
      continue;
    }
    while(bucket[i].size() > 0 && k > 0){
      ans.push_back(bucket[i].back());
      bucket[i].pop_back();
      k--;
    }
  }
  return ans;
}

int main() {
  vector<int> nums = {1,1,1,2,2,3};
  int k = 2;
  vector<int> ans = topKFrequent(nums, k);
  for(int& num: ans){
    cout << num << " ";
  }
  cout << '\n';
 return 0;
}