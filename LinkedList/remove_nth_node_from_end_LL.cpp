#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* fast = head;
  ListNode* slow = head;
  for(int i=0; i<n; i++){
    fast = fast->next;
  }
  if(fast == NULL){
    return head->next;
  }
  while(fast->next != NULL){
    fast = fast->next;
    slow = slow ->next;
  }
  ListNode* delNode = slow->next;
  slow->next = delNode->next;
  delete delNode;
  return head;
}

void printList(ListNode* head) {
  while (head != nullptr) {
    cout << head->val << " ";
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

  int n = 2;
  head = removeNthFromEnd(head, n);

  cout << "After Removal: ";
  printList(head);

  while (head != nullptr) {
    ListNode* temp = head;
    head = head->next;
    delete temp;
  }


 return 0;
}