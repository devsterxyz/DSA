#include <iostream>
#include <array>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Twitter {
  unordered_map<int, unordered_set<int>> friends;
  unordered_map<int, vector<pair<int, int>>> tweets;
  int curr = 0;
public:
  Twitter() {

  }
  
  void postTweet(int userId, int tweetId) {
    tweets[userId].push_back({curr++, tweetId});
  }
  
  vector<int> getNewsFeed(int userId) {
    vector<int> ans;
    priority_queue<array<int, 4>> pq;

    if (!tweets[userId].empty()) {
      int i = tweets[userId].size() - 1;
      auto [time, id] = tweets[userId][i];
      pq.push({time, id, userId, i});
    }

    for (int followee : friends[userId]) {
      if (!tweets[followee].empty()) {
        int i = tweets[followee].size() - 1;
        auto [time, id] = tweets[followee][i];
        pq.push({time, id, followee, i});
      }
    }

    while (!pq.empty() && ans.size() < 10) {
      auto [time, id, uid, idx] = pq.top();
      pq.pop();

      ans.push_back(id);

      if (idx > 0) {
        int nextIdx = idx - 1;
        auto [nextTime, nextId] = tweets[uid][nextIdx];
        pq.push({nextTime, nextId, uid, nextIdx});
      }
    }

    return ans;
  }
  
  void follow(int followerId, int followeeId) {
    if (followerId != followeeId) {
      friends[followerId].insert(followeeId);
    }
  }
  
  void unfollow(int followerId, int followeeId) {
    friends[followerId].erase(followeeId);
  }
};
