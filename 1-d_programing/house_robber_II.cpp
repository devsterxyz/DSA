#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int t [101];
int rob1_memorization(vector<int>& nums, int i, int n){
  if(i > n){
    return 0;
  }

  if(t[i] != -1){
    return t[i];
  }

  int steal = nums[i] + rob1_memorization(nums, i+2, n);
  int skip = rob1_memorization(nums, i+1, n);

  return t[i] = max(steal, skip);
}

int rob2_memorization(vector<int>& nums){
  int n = nums.size();
  if(n == 1){
    return nums[0];
  }

  if(n == 2){
    return max(nums[0], nums[1]);
  }

  memset(t, -1, sizeof(t));
  int take_0th_house = rob1_memorization(nums, 0, n-2);
  memset(t, -1, sizeof(t));
  int take_1st_house = rob1_memorization(nums, 1, n-1);

  return max(take_0th_house, take_1st_house);
}

int bottomUp(vector<int>& nums, int n, int k){
  if(n == 1){
    return nums[0];
  }
  vector<int>t(n+1, 0);
  // t[i] = max stolen money till i house
  // no house
  t[k] = 0;
  // 1 house
  t[k] = nums[0];

  for(int i=k+1; i<=n; i++){
    int steal = nums[i-1] + t[i-2]; 
    int skip = t[i-1];
    t[i] = max(steal, skip);
  }
  return t[n];
}

int bottomUp2(vector<int>& nums){
  
}

int rob(vector<int>& nums) {
  // return rob2_memorization(nums);
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