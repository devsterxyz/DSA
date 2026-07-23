#include <iostream>
using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int solve(TreeNode* root, bool& ans){
  if(root == NULL){
    return 0;
  }
  int l = solve(root->left, ans);
  int r = solve(root->right, ans);
  if(abs(l - r) > 1){
    ans = false;
  }
  return max(l, r) + 1;
}

bool isBalanced(TreeNode* root) {
  bool ans = true;
  solve(root, ans);
  return ans; 
}


int main() {

  TreeNode *root = new TreeNode(1,
  new TreeNode(2, new TreeNode(4), new TreeNode(5)),
  new TreeNode(3));

  cout << isBalanced(root) << '\n';

 return 0;
}