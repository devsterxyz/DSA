#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
  unordered_set<int> hashset;
  for(int i=0; i<nums.size(); i++){
    auto it = hashset.find(nums[i]);
    if(it != hashset.end()){
      return true;
    }
    hashset.insert(nums[i]);
  }   
  return false;
}

int main() {

  int n;
  cout << "Enter size of array: ";
  cin >> n;

  vector<int> arr;
  cout << "Enter ele of array: ";
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }

  cout << containsDuplicate(arr) << endl;

 return 0;
}