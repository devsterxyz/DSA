#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
  vector<vector<int>> ans;
  if(points.size() == 0){
    return ans;
  }

  priority_queue<pair<int, pair<int, int>>> pq;

  for(int i=0; i<points.size(); i++){
    int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
    if(pq.size() < k){
      pq.push({dist, {points[i][0], points[i][1]}});
    }
    else{
      if(dist < pq.top().first){
        pq.pop();
        pq.push({dist, {points[i][0], points[i][1]}});
      }
    }
  }

  while(!pq.empty()){
    ans.push_back({pq.top().second.first, pq.top().second.second});
    pq.pop();
  }
  return ans;

}


int main() {

  auto runTest = [](const vector<vector<int>>& input, int k,
                   const vector<vector<int>>& expected) {
    vector<vector<int>> points = input;
    vector<vector<int>> actual = kClosest(points, k);
    if (actual == expected) {
      cout << "PASS\n";
      return true;
    }

    cout << "FAIL\nExpected:";
    for (const auto& point : expected)
      cout << " (" << point[0] << ", " << point[1] << ")";
    cout << "\nActual:";
    for (const auto& point : actual)
      cout << " (" << point[0] << ", " << point[1] << ")";
    cout << '\n';
    return false;
  };

  int passed = 0;
  passed += runTest({{1, 3}, {-2, 2}, {5, 8}, {0, 1}}, 2,
                    {{-2, 2}, {0, 1}});
  passed += runTest({{1, 3}, {-2, 2}, {0, 1}}, 1, {{0, 1}});
  passed += runTest({{1, 3}, {-2, 2}}, 2, {{1, 3}, {-2, 2}});
  passed += runTest({}, 2, {});
  cout << passed << "/4 tests passed\n";

 return 0;
}