#include <iostream>
#include <stack>
using namespace std;

class StockSpanner {
public:
  stack<pair<int, int>> st;
  StockSpanner() {
      
  }
  
  int next(int price) {
    int span = 1;
    while(!st.empty() && st.top().first <= price){
      span = span + st.top().second;
      st.pop();
    }
    st.push({price, span});
    return span;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main() {

  int n;
  cout << "Enter the number of stock prices: ";
  cin >> n;

  StockSpanner* obj = new StockSpanner();
  cout << "Enter the stock prices:" << endl;
  for(int i = 0; i < n; i++) {
    int price;
    cin >> price;
    int span = obj->next(price);
    cout << "Span for price " << price << ": " << span << endl;
  }

  delete obj;

 return 0;
}