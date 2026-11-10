#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(int idx, int t, vector<int> &coins, vector<vector<int>> &dp){
  if(idx == 0){
    if(t % coins[0] == 0){
      return t/coins[0];
    }
    return 1e9;
  }
  if(dp[idx][t] != -1){
    return dp[idx][t];
  }
  int notTake = 0 + solve(idx-1, t, coins, dp);
  int take = 1e9;
  if(coins[idx] <= t){
    int res = solve(idx, t - coins[idx], coins, dp);
    if (res != 1e9) {
      take = 1 + res;
    }
  }
  return dp[idx][t] = min(take, notTake);
}

int memorization(vector<int>& coins, int amount){
  int n = coins.size();
  vector<vector<int>> dp(n, vector<int>(amount+1, -1));
  int ans = solve(n-1, amount, coins, dp);
  if(ans >= 1e9){
    return -1;
  }
  return ans;
}

int bottomUp(vector<int>& coins, int amount){
  int n = coins.size();

  vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

  for(int t = 0; t <= amount; t++) {
    if(t % coins[0] == 0) {
      dp[0][t] = t / coins[0];
    }
    else {
      dp[0][t] = 1e9;
    }
  }

  for(int idx = 1; idx < n; idx++) {
    for(int t = 0; t <= amount; t++) {
      int notTake = dp[idx - 1][t];
      int take = 1e9;

      if(coins[idx] <= t) {
        take = 1 + dp[idx][t - coins[idx]];
      }

      dp[idx][t] = min(take, notTake);
    }
  }

  int ans = dp[n - 1][amount];

  if(ans >= 1e9) {
    return -1;
  }

  return ans;
}

int coinChange(vector<int>& coins, int amount) {
  // return memorization(coins, amount);
  return bottomUp(coins, amount);
}

int main() {
  vector<vector<int>> testCoins = {
    {1, 2, 5},
    {2},
    {1},
    {2, 5, 10, 1}
  };
  vector<int> amounts = {11, 3, 0, 27};
  vector<int> expected = {3, -1, 0, 4};

  for (int i = 0; i < amounts.size(); i++) {
    int result = coinChange(testCoins[i], amounts[i]);
    cout << "Test " << i + 1 << ": "
         << (result == expected[i] ? "PASS" : "FAIL")
         << " (expected " << expected[i] << ", got " << result << ")\n";
  }

 return 0;
}