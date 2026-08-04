#include <iostream>
using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if(root == NULL){
    return NULL;
  }
  if(root == p){
    return p;
  }
  if(root == q){
    return q;
  }

  TreeNode* l = lowestCommonAncestor(root->left, p, q);
  TreeNode* r = lowestCommonAncestor(root->right, p, q);
  if(l && r){
    return root;
  }
  return l ? l : r;
}


int main() {
  // Construct sample binary search tree:
  //       6
  //      / \
  //     2   8
  //    / \ / \
  //   0  4 7  9
  //     / \
  //    3   5
  TreeNode* root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);

  TreeNode* p = root->left;         // node 2
  TreeNode* q = root->right;        // node 8

  TreeNode* ans = lowestCommonAncestor(root, p, q);
  if(ans) cout << "LCA: " << ans->val << "\n";
  else cout << "LCA: NULL\n";

  return 0;

}