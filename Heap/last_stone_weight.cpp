#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int lastStoneWeight(vector<int>& stones) {
  priority_queue<int> pq;
  for(int i=0; i<stones.size(); i++){
    pq.push(stones[i]);
  }

  while(pq.size() > 1){
    int y = pq.top();
    pq.pop();
    int x = pq.top();
    pq.pop();

    if(y == x){
      continue;
    }
    pq.push(y - x);
  }
  
  if(pq.size() == 0){
    return 0;
  }

  return pq.top();
}


int main() {
  vector<int> stones1 = {2, 7, 4, 1, 8, 1};
  cout << "Test 1: " << lastStoneWeight(stones1) << " (expected 1)" << endl;

  vector<int> stones2 = {1};
  cout << "Test 2: " << lastStoneWeight(stones2) << " (expected 1)" << endl;

  vector<int> stones3 = {2, 2};
  cout << "Test 3: " << lastStoneWeight(stones3) << " (expected 0)" << endl;

  vector<int> stones4;
  cout << "Test 4: " << lastStoneWeight(stones4) << " (expected 0)" << endl;

 return 0;
}