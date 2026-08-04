#include <iostream>
#include <queue>
using namespace std;

class node {
  public:
    int data;
    node* left;
    node* right;

  node(int d){
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

node* buildTree(node* root){
  cout << "Enter the data for node: " << endl;
  int data;
  cin >> data;
  root = new node(data);
  
  if(data == -1){
    return NULL;
  }

  cout << "Enter data in inserting at left: " << endl;
  root->left = buildTree(root->left);
  cout << "Enter data for inserting at right: " << endl;
  root->right = buildTree(root->right);
  return root;
}

void levelOrderTraversal(node* root){
  queue<node*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()){
    node* temp = q.front();
    q.pop();

    if(temp == NULL){ // old level traversal is completed
      cout << endl;
      if(!q.empty()){
        q.push(NULL);
      }
    }
    else{ 
      cout << temp->data << " ";
      if(temp->left){
        q.push(temp->left);
      }
      if(temp->right){
        q.push(temp->right);
      }
    }
  }
}

void inorder(node* root){
  // base case
  if(root == NULL){
    return;
  }
  
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void preorder(node* root){
  // base case
  if(root == NULL){
    return;
  }
  
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(node* root){
  // base case
  if(root == NULL){
    return;
  }
  
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

void buildFromLevelOrder(node* &root){
  queue<node*> q;
  cout << "Enter data for root: " << endl;
  int data;
  cin >> data;
  root = new node(data);
  q.push(root);

  while(!q.empty()){
    node* temp = q.front();
    q.pop();

    cout << "Enter left node for: " << temp->data << endl;
    int leftData;
    cin >> leftData;
    if(leftData != -1){
      temp->left = new node(leftData);
      q.push(temp->left);
    }

    cout << "Enter right node for: " << temp->data << endl;
    int rightData;
    cin >> rightData;
    if(rightData!= -1){
      temp->right = new node(rightData);  
      q.push(temp->right);
    }
  }
}

int main() {

  node* root = NULL;

  buildFromLevelOrder(root);
  levelOrderTraversal(root);
  /*
  // creating a tree
  root = buildTree(root);
  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  // level order
  levelOrderTraversal(root);

  cout << "inorder traversal is: " << endl;
  inorder(root);
  cout << "preorder traversal is: " << endl;
  preorder(root);
  cout << "postorder tranversal is : " << endl;
  postorder(root);

 return 0;
 */
}