#include <iostream>
#include <vector>
using namespace std;


int maxProduct(vector<int>& nums) {
  int n = nums.size();
  int res = nums[0];
  int curMin = 1;
  int curMax = 1;

  for(int i=0; i<n; i++){

    if(nums[i] == 0){
      curMax = 1;
      curMin = 1;
      res = max(res, 0);
      continue;
    }
    int tempMax = curMax * nums[i];
    int tempMin = curMin * nums[i];
    curMax = max(nums[i], max(tempMax, tempMin));
    curMin = min(nums[i], min(tempMax, tempMin));
    res = max(curMax, res);
  }
  return res;
}

int main() {

  int n; 
  cout << "Enter the size of arr: ";
  cin >> n;

  vector<int> arr;
  cout << "Enter the ele of arr: ";
  for(int i=0; i<arr.size(); i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }

  cout << "largest product: " << maxProduct(arr);

 return 0;
}