#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
  ListNode* fast = head;
  ListNode* slow = head;
  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(fast == slow){
      slow = head;
      while(fast != slow){
        slow = slow->next;
        fast = fast->next;
      }
      return fast;
    }
  }
  return NULL;
}


int main() {

  ListNode* head = new ListNode(3);
  ListNode* second = new ListNode(2);
  ListNode* third = new ListNode(0);
  ListNode* fourth = new ListNode(-4);

  head->next = second;
  second->next = third;
  third->next = fourth;

  fourth->next = second;

  ListNode* cycleStart = detectCycle(head);

  if (cycleStart != NULL) {
    cout << "Cycle starts at node with value: " << cycleStart->val << endl;
  } else {
    cout << "No cycle found." << endl;
  }

  return 0;

}