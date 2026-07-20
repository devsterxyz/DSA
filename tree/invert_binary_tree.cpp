#include <iostream>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *invertTree(TreeNode *root)
{
  if (root == NULL)
  {
    return NULL;
  }
  TreeNode *temp = root->left;
  root->left = root->right;
  root->right = temp;
  invertTree(root->left);
  invertTree(root->right);
  return root;
}

int main()
{
  TreeNode *root = new TreeNode(4,
  new TreeNode(2, new TreeNode(1), new TreeNode(3)),
  new TreeNode(7, new TreeNode(6), new TreeNode(9)));

  root = invertTree(root);

  cout << root->val << ' '
  << root->left->val << ' ' << root->right->val << ' '
  << root->left->left->val << ' ' << root->left->right->val << ' '
  << root->right->left->val << ' ' << root->right->right->val << '\n';

  return 0;
}