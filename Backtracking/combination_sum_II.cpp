#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int> &candidates, int target, int idx, vector<int> &temp, vector<vector<int>> &ans)
{
  if (target < 0)
  {
    return;
  }
  if (target == 0)
  {
    ans.push_back(temp);
    return;
  }
  for (int i = idx; i < candidates.size(); i++)
  {
    if (i > idx && candidates[i] == candidates[i - 1])
    {
      continue;
    }
    temp.push_back(candidates[i]);
    solve(candidates, target - candidates[i], i + 1, temp, ans);
    temp.pop_back();
  }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
  vector<vector<int>> ans;
  vector<int> temp;
  sort(begin(candidates), end(candidates));
  solve(candidates, target, 0, temp, ans);
  return ans;
}

int main()
{
  // Test case 1
  vector<int> candidates1 = {10, 1, 2, 7, 6, 1, 5};
  int target1 = 8;
  vector<vector<int>> result1 = combinationSum2(candidates1, target1);
  cout << "Test case 1 - Target: " << target1 << endl;
  for (auto &combo : result1)
  {
    for (int num : combo)
    {
      cout << num << " ";
    }
    cout << endl;
  }
  cout << endl;

  // Test case 2
  vector<int> candidates2 = {2, 5, 2, 1, 2};
  int target2 = 5;
  vector<vector<int>> result2 = combinationSum2(candidates2, target2);
  cout << "Test case 2 - Target: " << target2 << endl;
  for (auto &combo : result2)
  {
    for (int num : combo)
    {
      cout << num << " ";
    }
    cout << endl;
  }
  cout << endl;

  // Test case 3
  vector<int> candidates3 = {1};
  int target3 = 1;
  vector<vector<int>> result3 = combinationSum2(candidates3, target3);
  cout << "Test case 3 - Target: " << target3 << endl;
  for (auto &combo : result3)
  {
    for (int num : combo)
    {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}