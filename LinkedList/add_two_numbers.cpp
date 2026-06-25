#include <iostream>
using namespace std;



struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* temp1 = l1;
  ListNode* temp2 = l2;
  ListNode* dNode = new ListNode(-1);
  ListNode* cur = dNode;
  int carry = 0;
  while(temp1 != NULL || temp2 != NULL){
    int sum = 0;
    int temp1Val;
    int temp2Val;
    if(temp1 == NULL){
      temp1Val = 0;
    }
    else{
      temp1Val = temp1->val;
    }
    if(temp2 == NULL){
      temp2Val = 0;
    }
    else{
      temp2Val = temp2->val;
    }
    sum = temp1Val + temp2Val + carry;
    ListNode* newNode = new ListNode(sum%10);
    carry = sum/10;
    cur->next = newNode;
    cur = cur->next;
    if(temp1){
      temp1 = temp1->next;
    }
    if(temp2){
      temp2  = temp2->next;
    }
  }
  if(carry){
    ListNode* newNode = new ListNode(carry);
    cur->next = newNode;
  }
  return dNode->next;
}


int main() {

  ListNode* l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  ListNode* l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  ListNode* result = addTwoNumbers(l1, l2);

  cout << "Result: ";
  while (result != nullptr) {
    cout << result->val;
    if (result->next != nullptr)
      cout << " -> ";
    result = result->next;
  }
  cout << endl;

 return 0;
}