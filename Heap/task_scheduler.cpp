#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int leastInterval(vector<char>& tasks, int n) {
  vector<int> mp(26, 0);
  for(char &ch: tasks){
    mp[ch - 'A']++;
  }
  int time = 0;

  priority_queue<int> pq;

  for(int i=0; i<26; i++){
    if(mp[i] > 0){
      pq.push(mp[i]);
    }
  }

  while(!pq.empty()){
      vector<int> temp;
      for(int i=1; i <= n+1; i++){
        if(!pq.empty()){
          int freq = pq.top();
          pq.pop();
          freq--;
          temp.push_back(freq);
        }
      }

      for(int &f : temp){
        if(f > 0){
          pq.push(f);
        }
      }

      if(pq.empty()){
        time += temp.size();
      }
      else{
        time += n+1;
      }

  }
  return time;
}


int main() {
  vector<vector<char>> testTasks = {
      {'A', 'A', 'A', 'B', 'B', 'B'},
      {'A', 'A', 'A', 'B', 'B', 'B'},
      {'A', 'A', 'A', 'B', 'B', 'B'},
      {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'}
  };
  vector<int> cooldowns = {2, 0, 1, 2};

  for (size_t i = 0; i < testTasks.size(); ++i) {
    cout << "Test case " << i + 1 << ": "
         << leastInterval(testTasks[i], cooldowns[i]) << endl;
  }

  return 0;
}