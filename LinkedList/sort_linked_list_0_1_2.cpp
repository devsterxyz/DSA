#include <iostream>
using namespace std;

struct ListNode{
  int data;
  ListNode *next;
  ListNode() : data(0), next(nullptr) {}
  ListNode(int x) : data(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : data(x), next(next) {}
};

ListNode* sortList(ListNode* &head) {
  if(head == NULL || head->next == NULL){
    return head;
  }
  ListNode* zeroHead = new ListNode(-1);
  ListNode* oneHead = new ListNode(-1);
  ListNode* twoHead = new ListNode(-1);
  ListNode* zero = zeroHead;
  ListNode* one = oneHead;
  ListNode* two = twoHead;
  ListNode* temp = head;
  while(temp != NULL){
    if(temp->data == 0){
      zero->next = temp;
      zero = temp;
    }
    else if(temp->data == 1){
      one->next = temp;
      one = temp;
    }
    else if(temp->data == 2){
      two->next = temp;
      two = temp;
    }
    temp = temp->next;
  }
  zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
  one->next = twoHead->next;
  two->next = nullptr;
  head = zeroHead->next;
  zeroHead->next = nullptr;
  oneHead->next = nullptr;
  twoHead->next = nullptr;
  delete zeroHead;
  delete oneHead;
  delete twoHead;
  return head;
}

void printList(ListNode* head) {
  while(head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {

  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(1);
  head->next->next->next->next = new ListNode(2);
  head->next->next->next->next->next = new ListNode(0);

  cout << "Original List: ";
  printList(head);

  sortList(head);

  cout << "Sorted List: ";
  printList(head);

  while(head) {
    ListNode* temp = head;
    head = head->next;
    delete temp;
  }


 return 0;
}