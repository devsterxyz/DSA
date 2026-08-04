#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int solve(TreeNode* root,int& ans){
  if(root == NULL){
    return 0;
  }
  int left = solve(root->left, ans);
  int right = solve(root->right, ans);
  ans = max(ans, left+right);
  return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
  int ans = INT_MIN;
  solve(root, ans);
  return ans;
}

int main() {

  TreeNode *root = new TreeNode(1,
  new TreeNode(2, new TreeNode(4), new TreeNode(5)),
  new TreeNode(3));

  cout << diameterOfBinaryTree(root) << '\n';

 return 0;
}