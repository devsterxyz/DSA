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

bool isSameTree(TreeNode* p, TreeNode* q) {
  if(p == NULL && q == NULL){
    return true;
  }
  if(p == NULL || q == NULL){
    return false;
  }
  if(p->val != q->val){
    return false;
  }
  bool l = isSameTree(p->left, q->left);
  bool r = isSameTree(p->right, q->right);
  return (l && r);   
}

int main() {

  TreeNode *p = new TreeNode(1,
  new TreeNode(2, new TreeNode(4), new TreeNode(5)),
  new TreeNode(3));

  TreeNode *q = new TreeNode(1,
  new TreeNode(2, new TreeNode(4), new TreeNode(5)),
  new TreeNode(3));

  cout << isSameTree(p, q) << '\n';

 return 0;
}