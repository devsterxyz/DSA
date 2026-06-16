#include <iostream>
using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseLL(ListNode* head){
  if(head == NULL || head->next == NULL){
    return head;
  }
  ListNode* newHead = reverseLL(head->next);
  ListNode* front = head->next;
  front->next = head;
  head->next = NULL;
  return newHead;
}

bool isPalindrome(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;
  while(fast->next != NULL && fast->next->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  ListNode* newHead = reverseLL(slow->next);
  ListNode* first = head;
  ListNode* secound = newHead;
  while(secound != NULL){
    if(first->val != secound->val){
      reverseLL(newHead);
      return false;
    }
    first = first->next;
    secound = secound->next;
  }
  reverseLL(newHead);
  return true;
}

int main() {

  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(2);
  head->next->next->next->next = new ListNode(1);

  if (isPalindrome(head))
    cout << "Palindrome" << endl;
  else
    cout << "Not Palindrome" << endl;


 return 0;
}