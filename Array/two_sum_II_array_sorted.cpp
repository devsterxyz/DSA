#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
  int low = 0;
  int high = numbers.size() - 1;
  while(low <= high){
    if(numbers[low] + numbers[high] == target){
      return {low+1, high+1};
    }
    else if(numbers[low] + numbers[high] > target){
      high--;
    }
    else{
      low++;
    }
  }
  return {-1, -1};
}

int main() {

  vector<int> arr1;
  cout << "Enter size of 1st array" << endl;
  int s1;
  cin >> s1;

  cout << "Enter elem of 1st array in sorted order" << endl; 
  for(int i=0; i<s1; i++){
    int x;
    cin >> x;
    arr1.push_back(x);
  }

  int target;
  cout << "Enter target: ";
  cin >> target;

  vector<int> ans = twoSum(arr1, target);

  for(int i=0; i<ans.size(); i++){
    cout << ans[i] << " ";
  }
  


 return 0;
}