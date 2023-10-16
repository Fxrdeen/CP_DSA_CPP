// Code To reverse a Linked List in C++;

#include <iostream>
using namespace std;
class node{
public:
  int data;
  node* next;

  node(int val){
    data = val;
    next = NULL;
  }
};

node* reverse(node* &head){
  node* prev = NULL;
  node* curr=head;
  node* next;

  while(curr!=NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
  return head;

}

node* reverseK(node* &head, int k){
  node* prev=NULL;
  node* curr = head;
  node* next;
  int count=0;
  while(curr!=NULL && count<k){
    next = curr->next;
    curr->next = prev;
    prev=curr;
    curr=next;
    count++;
  }
  if (next!=NULL){
    head->next = reverseK(next, k);
  }
  return prev;
}

void insertAtTail(node* &head, int val){
  node* temp = new node(val);
  if (head==NULL){
    head = temp;
    return ;
  }
  node* p = head;
  while(p->next != NULL){
    p = p->next;
  }
  p->next = temp;

}
void display(node* head){
  node* temp = head;
  while(temp!=NULL){
    cout << temp->data << "->";
    temp=temp->next;
  }
  cout << "NULL\n";
}



int main(){

  node* head = NULL;
  insertAtTail(head, 1);
  insertAtTail(head, 2); 
  insertAtTail(head, 3);
  insertAtTail(head, 4);
  insertAtTail(head, 5);
  insertAtTail(head, 6);
  node* newhead = reverseK(head,2);
  display(newhead);
}
