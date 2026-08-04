#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<int> rightSideView(TreeNode* root) {
  if(root == NULL){
    return {};
  }
  queue<TreeNode*> q;
  vector<int> ans;
  q.push(root);
  while(!q.empty()){
    int n = q.size();
    TreeNode* node = NULL;
    while(n--){
      node = q.front();
      q.pop();
      if(node->left != NULL){
        q.push(node->left);
      }
      if(node->right != NULL){
        q.push(node->right);
      }
    }
    ans.push_back(node->val);
  }
  return ans;
}


int main() {
  // Test case 1: [1,2,3,null,5,null,4]
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(4);
  
  vector<int> result = rightSideView(root);
  
  cout << "Right Side View: ";
  for(int val : result) {
    cout << val << " ";
  }
  cout << endl;
  
  return 0;
}