#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
  ListNode* slow = head;
  ListNode* fast = head;
  while(fast != NULL && fast->next != NULL){
    fast = fast->next->next;
    slow = slow->next;
    if(fast == slow){
      return true;
    }
  }
  return false;
}

int main() {

  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  head->next->next->next->next->next = head->next->next;

  if (hasCycle(head)) {
    cout << "Cycle detected" << endl;
  } else {
    cout << "No cycle detected" << endl;
  }


 return 0;
}