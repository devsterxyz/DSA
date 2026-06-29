#include <iostream>
#include <vector>
using namespace std;


int maxArea(vector<int>& height) {
  int low = 0;
  int high = height.size() - 1;
  int ans = 0;
  while(low < high){
    int curr = 0;
    if(height[low] > height[high]){
      curr = (high - low) * height[high];
    }
    else{
      curr = (high - low) * height[low];
    }
    ans = max(ans, curr);
    if(height[low] < height[high]){
      low++;
    }
    else{
      high--;
    }
  }
  return ans;
}


int main() {

  vector<int> arr;
  cout << "Enter size of array" << endl;
  int k;
  cin >> k;

  cout << "Enter elem of 1st array in sorted order" << endl; 
  for(int i=0; i<k; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }

  cout << maxArea(arr) << endl;

 return 0;
}