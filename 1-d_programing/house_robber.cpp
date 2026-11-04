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

int bottomUp2(vector<int>& nums){
  int n = nums.size();
  if(n == 1){
    return nums[0];
  }
  vector<int> t(n+1, 0);
  // t[i] = money stolen when you have i houses

  t[0] = 0;
  // case - 1 (Take 1st house - hence skip the last house)

  for(int i = 1; i<=n-1; i++){
    int skip = t[i-1];
    int take = nums[i-1] + ((i-2 >= 0) ? t[i-2] : 0 );
    t[i] = max(skip, take);
  }

  int result1 = t[n-1];

  t.assign(n + 1, 0);
  // case - 2 (Skip 1st house - hence you can that the last house)
  t[0] = 0;
  t[1] = 0;
  for(int i = 2; i<=n; i++){
    int skip = t[i-1];
    int take = nums[i-1] + ((i-2 >= 0) ? t[i-2] : 0 );
    t[i] = max(skip, take);
  }

  int result2 = t[n];

  return max(result1, result2);
}

int rob(vector<int>& nums) {
  // return memeorization(nums, 0);

  return bottomUp2(nums);
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