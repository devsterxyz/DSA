#include <iostream>
#include <vector>
using namespace std;


int solve(vector<int>& nums, int i, int Xor){
  if(i == nums.size()){
    return Xor;
  }
  int include = solve(nums, i+1, nums[i]^Xor);
  int exclude = solve(nums, i+1, Xor);

  return include + exclude;
}

int subsetXORSum(vector<int>& nums) {
  return solve(nums, 0, 0);
}

int main() {
  // Test cases
  vector<int> tc1 = {1, 3}; // expected 6
  cout << "sum of subset XORs for {1,3}: " << subsetXORSum(tc1) << "\n";

  vector<int> tc2 = {5, 1, 6};
  cout << "sum of subset XORs for {5,1,6}: " << subsetXORSum(tc2) << "\n";

  vector<int> tc3 = {0}; // expected 0
  cout << "sum of subset XORs for {0}: " << subsetXORSum(tc3) << "\n";

  vector<int> tc4 = {2,4,8,16};
  cout << "sum of subset XORs for {2,4,8,16}: " << subsetXORSum(tc4) << "\n";

  return 0;
}