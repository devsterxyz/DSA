#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int findKthLargest(vector<int>& nums, int k) {

  priority_queue<int, vector<int>, greater<int>> pq;
  
  for(int i=0; i<nums.size(); i++){
    int num = nums[i];
    pq.push(num);

    if(pq.size() > k){
      pq.pop();
    }
  }

  return pq.top();
}


int main() {
  auto check = [](vector<int> nums, int k, int expected) {
    int actual = findKthLargest(nums, k);
    if (actual == expected) {
      cout << "PASS: k=" << k << ", result=" << actual << '\n';
    } else {
      cout << "FAIL: k=" << k << ", expected=" << expected
           << ", got=" << actual << '\n';
    }
  };

  check({3, 2, 1, 5, 6, 4}, 2, 5);
  check({3, 2, 3, 1, 2, 4, 5, 5, 6}, 4, 4);
  check({7}, 1, 7);
  check({-1, -2, -3, -4}, 2, -2);
  check({5, 5, 5, 5}, 3, 5);
  check({1, 2, 3, 4}, 4, 1);

  return 0;
}