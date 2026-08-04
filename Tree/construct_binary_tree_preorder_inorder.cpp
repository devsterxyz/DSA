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

TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx){
  if(start > end){
    return NULL;
  }
  int rootVal = preorder[idx];
  int i = start;
  for(; i<=end; i++){
    if(inorder[i] == rootVal){
      break;
    }
  }
  idx++;
  TreeNode* root = new TreeNode(rootVal);
  root->left = solve(preorder, inorder, start, i-1, idx);
  root->right = solve(preorder, inorder, i+1, end, idx);

  return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  int n = preorder.size();
  int idx = 0;
  return solve(preorder, inorder, 0, n-1, idx);
}

void printTree(TreeNode* root) {
  if (!root) return;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* node = q.front();
    q.pop();
    cout << node->val << " ";
    if (node->left) q.push(node->left);
    if (node->right) q.push(node->right);
  }
  cout << endl;
}

int main() {

  // Test case 1: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
  vector<int> preorder = {3,9,20,15,7};
  vector<int> inorder = {9,3,15,20,7};
  
  TreeNode* root = buildTree(preorder, inorder);
  
  cout << "Test case 1: ";
  printTree(root);

  // Test case 2: preorder = [-1], inorder = [-1]
  vector<int> preorder2 = {-1};
  vector<int> inorder2 = {-1};
  
  TreeNode* root2 = buildTree(preorder2, inorder2);
  
  cout << "Test case 2: ";
  printTree(root2);
  

 return 0;
}