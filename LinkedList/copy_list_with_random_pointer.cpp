#include <iostream>
using namespace std;


struct Node {
  int val;
  Node* next;
  Node* random;
  
  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

Node* copyRandomList(Node* head) {
  Node* temp = head;
  while(temp != NULL){
    Node* front = temp->next;
    Node* newNode = new Node(temp->val);
    temp->next = newNode;
    newNode->next = front;
    temp = front;
  }
  temp = head;
  while(temp){
    if(temp->random){
      temp->next->random = temp->random->next;
    }
      temp = temp->next->next;
  }
  Node* dNode = new Node(-1);
  Node* res = dNode;
  temp = head;
  while(temp != NULL){
    res->next = temp->next;
    res = res->next;
    temp->next = temp->next->next;
    res->next = nullptr;
    temp = temp->next;
  }
  return dNode->next;
}

void printList(Node* head) {
  while (head) {
    cout << "Node: " << head->val;
    if (head->random)
      cout << ", Random: " << head->random->val;
    else
      cout << ", Random: NULL";
    cout << endl;
    head = head->next;
  }
}

int main() {

  Node* n1 = new Node(1);
  Node* n2 = new Node(2);
  Node* n3 = new Node(3);
  Node* n4 = new Node(4);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;

  n1->random = n3;
  n2->random = n1;
  n3->random = n4;
  n4->random = n2;

  cout << "Original List:\n";
  printList(n1);

  Node* copiedHead = copyRandomList(n1);

  cout << "\nCopied List:\n";
  printList(copiedHead);

 return 0;
}