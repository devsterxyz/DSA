#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


bool containsNearbyDuplicate(vector<int>& nums, int k) {
  int n = nums.size();
  unordered_set<int> st;
  int i = 0, j = 0;
  while(j<n){
    if(abs(i-j) > k){
      st.erase(nums[i]);
      i++;
    }
    if(st.find(nums[j]) != st.end()){
      return true;
    }
    st.insert(nums[j]);
    j++;
  }
  return false;
}


int main() {

  int n, k;
  cout << "Enter the number of elements in the array: ";
  cin >> n;

  vector<int> nums(n);
  cout << "Enter the elements of the array:" << endl;
  for(int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  cout << "Enter the value of k: ";
  cin >> k;

  bool result = containsNearbyDuplicate(nums, k);
  if(result) {
    cout << "The array contains nearby duplicates within distance " << k << "." << endl;
  } else {
    cout << "The array does not contain nearby duplicates within distance " << k << "." << endl;
  }

 return 0;
}