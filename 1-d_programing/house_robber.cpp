#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int t[101];

int memeorization(vector<int>& nums, int i){
  if(i >= nums.size()){
    return 0;
  }

  if(t[i] != -1){
    return t[i];
  }

  int steal = nums[i] + memeorization(nums, i+2);
  int skip = memeorization(nums, i+1);

  return t[i] = max(steal, skip);
}

int bottomUp(vector<int>& nums){
  int n = nums.size();
  if(n == 1){
    return nums[0];
  }
  vector<int>t(n+1, 0);
  // t[i] = max stolen money till i house
  // no house
  t[0] = 0;
  // 1 house
  t[1] = nums[0];

  for(int i=2; i<=n; i++){
    int steal = nums[i-1] + t[i-2]; 
    int skip = t[i-1];
    t[i] = max(steal, skip);
  }
  return t[n];
}

int rob(vector<int>& nums) {
  // return memeorization(nums, 0);

  return bottomUp(nums);
}


int main() {

  int n;
  cout << "Enter the size of array: ";
  cin >> n;

  vector<int> nums;
  cout << "Enter ele in array: ";
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    nums.push_back(x);
  }

  memset(t, -1, sizeof(t));
  cout << rob(nums);

 return 0;
}