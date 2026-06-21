#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head->next;
  while(fast != NULL && fast->next != NULL){
    fast = fast->next->next;
    slow = slow->next;
  }
  ListNode* half = slow->next;
  slow->next = nullptr;

  ListNode* prev = nullptr;
  while(half != NULL){
    ListNode* temp = half->next;
    half->next = prev;
    prev = half;
    half = temp;
  }
  
  ListNode* first = head;
  ListNode* secound = prev;
  while(secound != NULL){
    ListNode* temp1 = first->next;
    ListNode* temp2 = secound->next;
    first->next = secound;
    secound->next = temp1;
    first = temp1;
    secound = temp2;
  }
}

void printList(ListNode* head) {
  while (head != nullptr) {
    cout << head->val;
    if (head->next) cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

int main() {

  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  cout << "Original List: ";
  printList(head);

  reorderList(head);

  cout << "Reordered List: ";
  printList(head);

  return 0;

}