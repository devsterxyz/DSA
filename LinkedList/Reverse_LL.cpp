#include <iostream>
using namespace std;

 struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
  ListNode* prev = nullptr;
  ListNode* cur = head;

  while(cur != NULL){
    ListNode* front = cur->next;
    cur->next = prev;
    prev = cur;
    cur = front;
  }
  return prev;
}

void printList(ListNode* head) {
  while (head != NULL) {
    cout << head->val;
    if (head->next != NULL) cout << " -> ";
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

  head = reverseList(head);

  cout << "Reversed List: ";
  printList(head);


  while (head != NULL) {
    ListNode* temp = head;
    head = head->next;
    delete temp;
  }

 return 0;
}