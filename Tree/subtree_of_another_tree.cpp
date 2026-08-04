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



bool sameTree(TreeNode* root, TreeNode* subRoot) {
  if (root == NULL && subRoot == NULL) {
    return true;
  }
  if (root == NULL || subRoot == NULL) {
    return false;
  }
  if (root->val != subRoot->val) {
    return false;
  }
  bool l = sameTree(root->left, subRoot->left);
  bool r = sameTree(root->right, subRoot->right);
  return (l & r);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
  if (root == NULL) {
    return false;
  }
  if (root->val == subRoot->val && sameTree(root, subRoot)) {
    return true;
  }
  bool l = isSubtree(root->left, subRoot);
  bool r = isSubtree(root->right, subRoot);
  return (l || r);
}


int main() {
  // Create main tree
  //       3
  //      / \
  //     4   5
  //    / \
  //   1   2
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(4);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(2);

  // Create subtree to check
  //     4
  //    / \
  //   1   2
  TreeNode* subRoot = new TreeNode(4);
  subRoot->left = new TreeNode(1);
  subRoot->right = new TreeNode(2);
  // subRoot->right = new TreeNode(5);

  // Check if subRoot is subtree of root
  if (isSubtree(root, subRoot)) {
    cout << "SubTree found!" << endl;
  } else {
    cout << "SubTree not found!" << endl;
  }

  return 0;
}