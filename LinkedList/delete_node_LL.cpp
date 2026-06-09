#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
  ListNode* prev = NULL;
  while (node != NULL && node->next != NULL) {
    node->val = node->next->val;
    prev = node;
    node = node->next;
  }
  prev->next = NULL;
  delete node;
}

void printList(ListNode* head) {
  while (head != NULL) {
    cout << head->val;
    if (head->next != NULL)
      cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  ListNode* head = new ListNode(4);
  head->next = new ListNode(5);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(9);

  cout << "Original List: ";
  printList(head);

  deleteNode(head->next);

  cout << "After Deletion: ";
  printList(head);

  while (head != NULL) {
    ListNode* temp = head;
    head = head->next;
    delete temp;
  }

  return 0;
}