#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head) {
  if(head == NULL || head->next == NULL){
    return head;
  }
  ListNode* odd = head;
  ListNode* even = head->next;
  ListNode* evenNode = head->next;
  while(even != NULL && even->next != NULL){
    odd->next = odd->next->next;
    odd = odd->next;
    even->next = even->next->next;
    even = even->next;
  }
  odd->next = evenNode;
  return head;
}

void printList(ListNode* head) {
  while (head != NULL) {
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

  head = oddEvenList(head);

  cout << "After Odd-Even Rearrangement: ";
  printList(head);

 return 0;
}