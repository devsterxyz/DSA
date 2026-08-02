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

int maxSum;

int solve(TreeNode* root){
  if(root == NULL){
    return 0;
  }
  int l = solve(root->left);
  int r = solve(root->right);
  int neecha_hi_milgaya_ans = l + r + root->val;
  int koi_ek_acha = max(l, r) + root->val;
  int only_ek_acha = root->val;
  maxSum = max(maxSum, max(neecha_hi_milgaya_ans, max(koi_ek_acha, only_ek_acha)));
  return max(koi_ek_acha, only_ek_acha);
}

int maxPathSum(TreeNode* root) {
  maxSum = INT_MIN;
  solve(root);
  return maxSum;
}

int main() {
  TreeNode* root1 = new TreeNode(-10,
      new TreeNode(9),
      new TreeNode(20,
          new TreeNode(15),
          new TreeNode(7)));
  cout << "Test1: " << maxPathSum(root1) << "\n";

  TreeNode* root2 = new TreeNode(1,
      new TreeNode(2),
      new TreeNode(3));
  cout << "Test2: " << maxPathSum(root2) << "\n";

  TreeNode* root3 = new TreeNode(-3);
  cout << "Test3: " << maxPathSum(root3) << "\n";

  return 0;
}