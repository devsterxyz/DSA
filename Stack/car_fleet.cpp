#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {
  stack<double> st;
  vector<pair<int, double>> time;
  for(int i=0; i<position.size(); i++){
    time.push_back({position[i], (double)(target-position[i])/speed[i]});
  }
  sort(time.begin(), time.end(), greater<pair<int, double>>());
  for(int i=0; i<time.size(); i++){
    double t = time[i].second;
    if(st.empty() || t > st.top()){
      st.push(t);
    }
  }
  return st.size();
}


int main() {

  int target;
  cout << "Enter the target position: ";
  cin >> target;

  int n;
  cout << "Enter the number of cars: ";
  cin >> n;

  vector<int> position(n);
  vector<int> speed(n);

  cout << "Enter the positions of the cars: ";
  for(int i = 0; i < n; i++) {
    cin >> position[i];
  }

  cout << "Enter the speeds of the cars: ";
  for(int i = 0; i < n; i++) {
    cin >> speed[i];
  }

  int fleetCount = carFleet(target, position, speed);
  cout << "Number of car fleets that will arrive at the destination: " << fleetCount << endl;

 return 0;
}