#include <iostream>
using namespace std;



struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 


ListNode* reverseBetween(ListNode* head, int left, int right) {
  ListNode* dummy = new ListNode(0, head);
  ListNode* cur = head;
  ListNode* leftPrev = dummy;
  for(int i=0; i<left-1; i++){
    leftPrev = cur;
    cur = cur->next;
  }
  ListNode* prev = nullptr;
  for(int i=0; i<(right-left+1); i++){
    ListNode* tmpNext = cur->next;
    cur->next = prev;
    prev = cur;
    cur = tmpNext;
  }
  leftPrev->next->next = cur;
  leftPrev->next = prev;
  return dummy->next;
}

void printList(ListNode* head) {
  while (head != nullptr) {
    cout << head->val;
    if (head->next != nullptr)
      cout << " -> ";
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

  int left = 2, right = 4;
  head = reverseBetween(head, left, right);

  cout << "After reversing from " << left << " to " << right << ": ";
  printList(head);

 return 0;
}