#include <iostream>
#include <vector>
#include <cstddef>
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


vector<long long> checkBTS(TreeNode* root, bool& flag){
  if(root == NULL){
    return {LLONG_MAX, LLONG_MIN};
  }

  vector<long long> l = checkBTS(root->left, flag);
  vector<long long> r = checkBTS(root->right, flag);

  if(l[1] >= root->val || r[0] <= root->val){
    flag = false;
  }

  return {min((long long)root->val, l[0]), max((long long)root->val, r[1])};
}

bool isValidBST(TreeNode* root) {
  bool flag = true;
  checkBTS(root, flag);
  return flag;
}


int main() {

  // Test case 1: [2,1,3]
  TreeNode* root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);
  
  bool result = isValidBST(root);
  
  cout << "Is Valid BST: " << (result ? "true" : "false") << endl << endl;

  // Test case 2: [5,1,4,null,null,3,6]
  TreeNode* root2 = new TreeNode(5);
  root2->left = new TreeNode(1);
  root2->right = new TreeNode(4);
  root2->right->left = new TreeNode(3);
  root2->right->right = new TreeNode(6);
  
  bool result2 = isValidBST(root2);
  
  cout << "Is Valid BST: " << (result2 ? "true" : "false") << endl;

 return 0;
}