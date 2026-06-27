#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2){
  if(l1 == NULL){
    return l2;
  }
  if(l2 == NULL){
    return l1;
  }
  if(l1->val <= l2->val){
    l1->next = mergeTwoSortedLists(l1->next, l2);
    return l1;
  }
  else{
    l2->next = mergeTwoSortedLists(l2->next, l1);
    return l2;
  }
  return NULL;
}

ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists){
  if(start > end){
    return NULL;
  }
  if(start == end){
    return lists[start];
  }
  int mid = start + ((end - start) / 2);
  ListNode* L1 = partitionAndMerge(start, mid, lists);
  ListNode* L2 = partitionAndMerge(mid+1, end, lists);
  return mergeTwoSortedLists(L1, L2);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
  int k = lists.size();
  if(k == 0){
    return NULL;
  }
  return partitionAndMerge(0, k-1, lists);
}

void printList(ListNode* head) {
  while (head != NULL) {
    cout << head->val;
    if (head->next != NULL)
      cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

int main() {

  ListNode* l1 = new ListNode(1);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(5);

  ListNode* l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);

  ListNode* l3 = new ListNode(2);
  l3->next = new ListNode(6);

  vector<ListNode*> lists;
  lists.push_back(l1);
  lists.push_back(l2);
  lists.push_back(l3);

  ListNode* mergedHead = mergeKLists(lists);

  cout << "Merged Linked List: ";
  printList(mergedHead);

 return 0;
}