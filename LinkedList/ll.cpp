#include <algorithm>
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

void insertAtHead(node* &head, int val){
  node* temp = new node(val);
  if (head==NULL){
    head = temp;
    return;
  }
  temp->next = head;
  head = temp;

}

void display(node* head){
  node* temp = head;
  while(temp!=NULL){
    cout << temp->data << "->";
    temp=temp->next;
  }
  cout << "NULL\n";
}


bool search(node* head, int val){
  node* temp = head;
  while(temp!=NULL){
    if (temp->data==val)
      return true;
    temp = temp->next;
  }
  return false;
}

void deleteAtHead(node* &head){
  node* todelete=head;
  head = head->next;
  delete todelete;
}

void deletion(node* &head, int val){
  if (head==NULL)
    return;
  if (head->next == NULL){
    deleteAtHead(head);
    return;
  }
  node* temp = head;
  while(temp->next->data!=val){
    temp=temp->next;
  }
  node* todelete = temp->next;
  temp->next = temp->next->next;
}

int main(){

  node* head = NULL;
  insertAtTail(head, 1);
  insertAtTail(head, 2); 
  insertAtTail(head, 3);
  insertAtHead(head, 4);
  display(head);
  deletion(head,3);
  display(head);
  deleteAtHead(head);
  display(head);
  return 0;
}

