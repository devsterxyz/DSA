#include <iostream>
#include <unordered_map>
using namespace std;


class Node {
public:
  int key, val;
  Node *prev, *next;

  Node(int k = 0, int v = 0) {
    key = k;
    val = v;
    prev = next = nullptr;
  }
};

class LRUCache {
public:
  unordered_map<int, Node*> mpp;
  int capacity;
  Node* head = new Node();
  Node* tail = new Node();

  void insterAfterHead(Node* node){
    Node* currAfterHead = head->next;
    head->next = node;
    node->next = currAfterHead;
    node->prev = head;
    currAfterHead->prev = node;
  }

  void deletNode(Node* node){
    Node* prevNode = node->prev;
    Node* afterNode = node->next;
    prevNode->next = afterNode;
    afterNode->prev = prevNode;
  }

  LRUCache(int capacity) {
    this->capacity = capacity;
    head->next = tail;
    tail->prev = head;
  }
  
  int get(int key) {
    if(mpp.find(key) == mpp.end()){
      return -1;
    }
    Node* node = mpp[key];
    deletNode(node);
    insterAfterHead(node);
    return node->val;
  }
  
  void put(int key, int value) {
    if(capacity == 0){
      return;
    }
    if(mpp.find(key) != mpp.end()){
      Node* node = mpp[key];
      node->val = value;
      deletNode(node);
      insterAfterHead(node);
    }
    else{
        if(mpp.size() == capacity){
          Node* node = tail->prev;
          mpp.erase(node->key);
          deletNode(node);
          delete node;
        }
      Node* node = new Node(key, value);
      mpp[key] = node;
      insterAfterHead(node);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {

 return 0;
}