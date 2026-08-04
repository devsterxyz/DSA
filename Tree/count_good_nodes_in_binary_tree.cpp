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
 

void countGoodNodes(TreeNode* root, int& count, int maxForThisStep){
  if(root == NULL){
    return;
  }
  if(root->val >= maxForThisStep){
    count++;
    maxForThisStep = root->val;
  }
  countGoodNodes(root->left, count, maxForThisStep);
  countGoodNodes(root->right, count, maxForThisStep);
}

int goodNodes(TreeNode* root) {
  int count = 0;
  if(!root){
    return count;
  }
  countGoodNodes(root, count, root->val);
  return count;
}

int main() {

  // Test case 1: [3,1,4,3,null,1,5]
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->left->left = new TreeNode(3);
  root->right->left = new TreeNode(1);
  root->right->right = new TreeNode(5);
  
  int result = goodNodes(root);
  
  cout << "Number of Good Nodes: " << result << endl;

 return 0;
}