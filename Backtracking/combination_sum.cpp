#include <iostream>
#include <vector>
using namespace std;



void findCombination(int i, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds){
  if(i == arr.size()){
      if(target == 0){
        ans.push_back(ds);
      }
      return;
  }
  if(arr[i] <= target){
    ds.push_back(arr[i]);
    findCombination(i, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
  findCombination(i+1, target, arr, ans, ds);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
  vector<vector<int>> ans;
  vector<int> ds;
  findCombination(0, target, candidates, ans, ds);
  return ans;
}



int main() {

  vector<int> candidates = {2, 3, 6, 7};
  int target = 7;
  vector<vector<int>> result = combinationSum(candidates, target);
  for (const auto& combination : result) {
    cout << "[";
    for (int i = 0; i < combination.size(); i++) {
      cout << combination[i];
      if (i < combination.size() - 1) cout << ",";
    }
    cout << "]" << endl;
  }

 return 0;
}