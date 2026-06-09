#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
  int data;
  Node* next;

  public:
  Node(int data1, Node* next1){
    data = data1;
    next = next1;
  }

  public:
  Node(int data1){
    data = data1;
    next = nullptr;
  }
};

Node* converArrToLL(vector<int> &arr){
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i=1; i<arr.size(); i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}

int lengthOfLL(Node* head){
  int cnt = 0;
  Node* temp = head;
  while(temp){
    temp = temp->next;
    cnt++;
  }
  return cnt;
}

int checkIfPresent(Node* head, int val){
  Node* temp = head;
  while(temp){
    if(temp->data == val){
      return 1;
    }
    temp = temp->next;
  }
  return 0;
}

void print(Node* head){
  Node* temp = head;
  while(temp){
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

Node* insertHead(Node* head, int val){
  Node* temp = new Node(val, head);
  return temp;
}

Node* insertTail(Node* head, int val){
  if(head == NULL){
    return new Node(val);
  }
  Node* temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  Node* newNode = new Node(val);
  temp->next = newNode;

  return head;
}

Node* insertPosition(Node* head, int ele, int k){
  if(head == NULL){
    if(k == 1){
      return new Node(ele);
    }
    else{
      return head;
    }
  }

  if(k == 1){
    return new Node(ele, head);
  }

  int cnt = 0;
  Node* temp = head;
  while(temp != NULL){
    cnt++;
    if(cnt == (k-1)){
      Node* x = new Node(ele, temp->next);
      temp->next = x;
      break;
    }
    temp = temp->next;
  }
  return head;
}

Node* insertBeforeValue(Node* head, int ele, int val){
  if(head == NULL){
    return NULL;
  }

  if(head->data == val){
    return new Node(ele, head);
  }

  Node* temp = head;
  while(temp->next != NULL){
    if(temp->next->data == val){
      Node* x = new Node(ele, temp->next);
      temp->next = x;
      break;
    }
    temp = temp->next;
  }
  return head;
}

Node* deletHead(Node* head){
  if(head == NULL) return head;

  Node* temp = head;
  head =  head->next;
  free(temp);  // delete temp; (it will also work)
  return head;
}

Node* deleteTail(Node* head){
  if(head == NULL || head->next == NULL) return NULL;

  Node* temp  = head;
  while(temp->next->next != NULL){
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;

  return head;
}

Node* removeK(Node* head, int k){
  if(head == NULL) return head;

  if(k == 1){
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
  }

  int cnt = 0;
  Node* temp = head;
  Node* prev = NULL;
  while(temp != NULL){
    cnt++;
    if(cnt == k){
      prev->next = prev->next->next;
      free(temp);
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
}

Node* removeEle(Node* head, int ele){
  if(head == NULL) return head;

  if(head->data == ele){
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
  }
  Node* temp = head;
  Node* prev = NULL;
  while(temp != NULL){
    if(temp->data == ele){
      prev->next = prev->next->next;
      free(temp);
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
}


int main(){
  vector<int> arr = {12, 5, 8, 7};
  Node* head = converArrToLL(arr);
  
  head = removeEle(head, 5);
  print(head);
}