#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* findMiddle(ListNode* head){
  ListNode* slow = head;
  ListNode* fast = head->next;

  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

ListNode* merge2(ListNode* list1, ListNode* list2){
  ListNode* t1 = list1;
  ListNode* t2 = list2;
  ListNode* dNode = new ListNode(-1);
  ListNode* temp = dNode;
  while(t1 != NULL && t2 != NULL){
      if(t1->val < t2->val){
        temp->next = t1;
        t1 = t1->next;
        temp = temp->next;
      }
      else{
        temp->next = t2;
        t2 = t2->next;
        temp = temp->next;
      }
  }
  if(t1){
    temp->next = t1;
  }
  else{
    temp->next = t2;
  }
  return dNode->next;
}

ListNode* sortList(ListNode* head) {
  if(head == NULL || head->next == NULL){
    return head;
  }
  ListNode* middle = findMiddle(head);
  ListNode* leftHead = head;
  ListNode* rightHead = middle->next;
  middle->next = NULL;
  leftHead = sortList(leftHead);
  rightHead = sortList(rightHead);
  return merge2(leftHead, rightHead);
}

int main() {

  ListNode* head = new ListNode(4);
  head->next = new ListNode(2);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(3);

  cout << "Original List: ";
  ListNode* temp = head;
  while(temp != NULL){
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;

  head = sortList(head);

  cout << "Sorted List: ";
  temp = head;
  while(temp != NULL){
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;

 return 0;
}