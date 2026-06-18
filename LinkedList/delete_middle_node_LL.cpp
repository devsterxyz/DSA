#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head) {
  while (head != NULL) {
    cout << head->val;
    if (head->next != NULL) cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

ListNode* deleteMiddle(ListNode* head) {
  if(head->next == NULL){
    return NULL;
  }
  ListNode* fast = head;
  ListNode* slow = head;
  fast = fast->next->next;
  while(fast != NULL && fast->next != NULL){
    fast = fast->next->next;
    slow = slow->next;
  }
  ListNode* delNode = slow->next;
  slow->next = delNode->next;
  delete delNode;
  return head;
}

int main() {

  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  cout << "Original List: ";
  printList(head);

  head = deleteMiddle(head);

  cout << "After Deleting Middle: ";
  printList(head);

  while (head != NULL) {
    ListNode* temp = head;
    head = head->next;
    delete temp;
  }

  return 0;
}