#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class FreqStack {
public:
  unordered_map<int, int> cnt;
  unordered_map<int, stack<int>> st;
  int maxCnt;
  FreqStack() {
    maxCnt = 0;
  }
  
  void push(int val) {
    int valCnt = ++cnt[val];
    if(valCnt > maxCnt){
      maxCnt = valCnt;
      st[valCnt] = stack<int>();
    }
    st[valCnt].push(val);
  }
  
  int pop() {
    int res = st[maxCnt].top();
    st[maxCnt].pop();
    cnt[res]--;
    if(st[maxCnt].empty()){
      maxCnt--;
    }
    return res;
  }
};


int main() {

  FreqStack freqStack;
  freqStack.push(5);
  freqStack.push(7);
  freqStack.push(5);
  freqStack.push(7);
  freqStack.push(4);
  freqStack.push(5);

  cout << "Pop: " << freqStack.pop() << endl; // returns 5
  cout << "Pop: " << freqStack.pop() << endl; // returns 7
  cout << "Pop: " << freqStack.pop() << endl; // returns 5
  cout << "Pop: " << freqStack.pop() << endl; // returns 4

 return 0;
}