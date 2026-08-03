#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string serialize(TreeNode *root)
{
  if (!root)
  {
    return "";
  }
  string s;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    TreeNode *curNode = q.front();
    q.pop();
    if (curNode == NULL)
    {
      s.append("null,");
    }
    else
    {
      s.append(to_string(curNode->val) + ",");
    }
    if (curNode != NULL)
    {
      q.push(curNode->left);
      q.push(curNode->right);
    }
  }
  return s;
}

TreeNode *deserialize(string data){
  if (data.size() == 0){
    return NULL;
  }
  stringstream s(data);
  string str;
  getline(s, str, ',');
  TreeNode *root = new TreeNode(stoi(str));
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()){
    TreeNode *node = q.front();
    q.pop();
    getline(s, str, ',');
    if (str == "null"){
      node->left = NULL;
    }
    else{
      TreeNode *leftNode = new TreeNode(stoi(str));
      node->left = leftNode;
      q.push(leftNode);
    }
    getline(s, str, ',');
    if (str == "null"){
      node->right = NULL;
    }
    else{
      TreeNode *rightNode = new TreeNode(stoi(str));
      node->right = rightNode;
      q.push(rightNode);
    }
  }
  return root;
}

int main(){

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  string serialized = serialize(root);
  cout << "Serialized: " << serialized << endl;

  TreeNode *deserialized = deserialize(serialized);
  string reserialized = serialize(deserialized);
  cout << "Deserialized and reserialized: " << reserialized << endl;

  return 0;
}