#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void treeToArray(TreeNode* root, vector<int>& arr){
  if(root == NULL){
    return;
  }
  treeToArray(root->left, arr);
  arr.push_back(root->val);
  treeToArray(root->right, arr);
}

int kthSmallest(TreeNode* root, int k) {
  vector<int> arr;
  treeToArray(root, arr);
  return arr[k-1];
}


int main() {

  // Test case 1: [3,1,4,null,2], k = 1
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->left->right = new TreeNode(2);
  
  int k = 1;
  int result = kthSmallest(root, k);
  
  cout << "Kth Smallest Element: " << result << endl << endl;

  // Test case 2: [5,3,6,2,4,null,null,1], k = 3
  TreeNode* root2 = new TreeNode(5);
  root2->left = new TreeNode(3);
  root2->right = new TreeNode(6);
  root2->left->left = new TreeNode(2);
  root2->left->right = new TreeNode(4);
  root2->left->left->left = new TreeNode(1);
  
  k = 3;
  result = kthSmallest(root2, k);
  
  cout << "Kth Smallest Element: " << result << endl;

 return 0;
}