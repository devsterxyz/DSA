#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node* back;

  public:
  Node(int data1, Node* next1, Node* back1){
    data = data1;
    next = next1;
    back = back1;
  }

  public:
  Node(int data1){
    data = data1;
    next = nullptr;
    back = nullptr;
  }
};

Node* reverseDLL(Node* head){
  if(head == NULL || head->next == NULL){
    return head;
  }

  Node* prev = NULL;
  Node* curr = head;
  while(curr != NULL){
    prev = curr->back;
    curr->back = curr->next;
    curr->next = prev;
    curr = curr->back;
  } 
  return prev->back;
}

void printDLL(Node* head){
  while(head != NULL){
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {

  Node* head = new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(3);
  Node* fourth = new Node(4);
  Node* fifth = new Node(5);

  head->next = second;

  second->back = head;
  second->next = third;

  third->back = second;
  third->next = fourth;

  fourth->back = third;
  fourth->next = fifth;

  fifth->back = fourth;

  cout << "Original DLL: ";
  printDLL(head);

  head = reverseDLL(head);

  cout << "Reversed DLL: ";
  printDLL(head);

  return 0;
}