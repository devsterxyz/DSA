#include <iostream>
using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* findKthNode(ListNode* temp, int k){
  k -= 1;
  while(temp != NULL && k>0){
    k--;
    temp = temp->next;
  }
  return temp;
}

ListNode* reverseList(ListNode* head){
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

ListNode* reverseKGroup(ListNode* head, int k) {
  ListNode* temp = head;
  ListNode* prevNode = new ListNode();
  ListNode* nextNode = new ListNode();
  while(temp != NULL){
    ListNode* kthNode = findKthNode(temp, k);
    if(kthNode == NULL){
      if(prevNode){
        prevNode->next = temp;
        break;
      }
    }
    nextNode = kthNode->next;
    kthNode->next = nullptr;
    reverseList(temp);
    if(temp == head){
      head = kthNode;
    }
    else{
      prevNode->next = kthNode;
    }
    prevNode = temp;
    temp = nextNode;
  }
  return head;
}


int main() {

  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  int k = 2;

  cout << "Original List: ";
  ListNode* temp = head;
  while (temp != nullptr) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;

  head = reverseKGroup(head, k);

  cout << "Reversed in Groups of " << k << ": ";
  temp = head;
  while (temp != nullptr) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;

  while (head != nullptr) {
    ListNode* next = head->next;
    delete head;
    head = next;
  }


 return 0;
}