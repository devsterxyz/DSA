#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int t[1001];

int memorization(int idx, vector<int>& cost){
  if(idx >= cost.size()){
    return 0;
  }

  if(t[idx] != -1){
    return t[idx];
  }

  int a = cost[idx] + memorization(idx+1, cost);
  int b = cost[idx] + memorization(idx+2, cost);
  return t[idx] = min(a, b);
}

int bottomUp(int n, vector<int>& cost){
  if(n == 2){
    return min(cost[0], cost[1]);
  }

  for(int i=2; i<n; i++){
    cost[i] = cost[i] + min(cost[i-1], cost[i-2]);
  }

  return min(cost[n-1], cost[n-2]);

}

int minCostClimbingStairs(vector<int>& cost) {
  int n = cost.size();
  // memset(t, -1, sizeof(t));
  // return min(memorization(0, cost), memorization(1, cost));

  return bottomUp(n, cost);
}


int main() {

  int n;
  cout << "Enter the size of array: ";
  cin >> n;

  vector<int> cost;
  cout << "Enter ele in array: ";
  for(int i=0; i<n; i++){
    int x;
    cin >> x;
    cost.push_back(x);
  }

  cout << minCostClimbingStairs(cost);

 return 0;
}