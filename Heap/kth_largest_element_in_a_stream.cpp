#include <iostream>
#include <queue>
using namespace std;

class KthLargest {
public:
  int K;
  priority_queue<int, vector<int>, greater<int>> pq;
  KthLargest(int k, vector<int>& nums) {
    K = k;
    for(int &num: nums){
      pq.push(num);

      if(pq.size() > k){
        pq.pop();
      }
    }
  }
  
  int add(int val) {
    pq.push(val);

    if(pq.size() > K){
      pq.pop();
    }

    return pq.top();
  }
};


int main() {
  vector<int> nums1 = {4, 5, 8, 2};
  KthLargest obj1(3, nums1);
  cout << obj1.add(3) << endl; // 4
  cout << obj1.add(5) << endl; // 5
  cout << obj1.add(10) << endl; // 5
  cout << obj1.add(9) << endl; // 8
  cout << obj1.add(4) << endl; // 8

  vector<int> nums2 = {1, 2, 3, 4, 5};
  KthLargest obj2(2, nums2);
  cout << obj2.add(6) << endl; // 5
  cout << obj2.add(1) << endl; // 4
  cout << obj2.add(2) << endl; // 4
  cout << obj2.add(3) << endl; // 3

  vector<int> nums3 = {5, 5, 5};
  KthLargest obj3(1, nums3);
  cout << obj3.add(1) << endl; // 5
  cout << obj3.add(10) << endl; // 10
  cout << obj3.add(2) << endl; // 10

  return 0;
}