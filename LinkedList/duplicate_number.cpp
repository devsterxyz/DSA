#include <iostream>
#include <vector>
using namespace std;


int findDuplicate(vector<int>& nums) {
  int slow = 0;
  int fast = 0;
  while(true){
    slow = nums[slow];
    fast = nums[nums[fast]];
    if(slow == fast){
      break;
    }
  }
  slow = 0;
  while(slow != fast){
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
}


int main() {
  vector<int> nums = {1, 3, 4, 2, 2};
  int duplicate = findDuplicate(nums);
  cout << "Duplicate number: " << duplicate << endl;

 return 0;
}