#include <iostream>
using namespace std;


struct ListNode{
  int val;
  ListNode *next;
  ListNode(){
    val = 0;
    next = NULL;
  }
  ListNode(int data1){
    val = data1;
    next = NULL;
  }
  ListNode(int data1, ListNode *next1){
    val = data1;
    next = next1;
  }
};

int findLengthOfLoop(ListNode *head) {
  ListNode* slow = head;
  ListNode* fast = head;
  int cnt = 0;
  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(fast == slow){
      slow = slow->next;
      cnt++;
      while(fast != slow){
        slow = slow->next;
        cnt++;
      }
      break;
    }
  }
  return cnt;
}

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  
  head->next->next->next->next->next = head->next->next;

  int loopLength = findLengthOfLoop(head);

  cout << "Length of loop: " << loopLength << endl;

  return 0;
}