#include <iostream>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root) {
  if(root == NULL){
    return 0;
  }
  int l = maxDepth(root->left);
  int r = maxDepth(root->right);
  return 1 + max(l, r);
}

int main() {

  TreeNode *root = new TreeNode(3,
  new TreeNode(9),
  new TreeNode(20, new TreeNode(15), new TreeNode(7)));

  cout << maxDepth(root) << '\n';

 return 0;
}