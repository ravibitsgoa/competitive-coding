#include<iostream>
/*
Reverse a linked list and return pointer to the head
The input list will have at least one element
Node is defined as*/
struct Node
{   int data;
    struct Node *next;
};
Node* Reverse (Node *head)
{ Node * prev=NULL, *nxt, *ptr=head;
  while(ptr!=NULL)
  { nxt=ptr->next;
    ptr->next=prev;
    prev=ptr;
    ptr=nxt;
  }
  return prev;
// Complete this method
}
using namespace std;

int main()
{ Node* p1=new Node(), *p2=new Node(), *p3=new Node();
  p1->data=1;
  p1->next=p2;
  p2->data=0;
  p2->next=p3;
  p3->data=3;
  p3->next=NULL;
  //cout<<p1->data<<p2->data;
  Node *head=p1;
  while(head!=NULL)
  { cout<<head->data;
    head=head->next;
  }
  head=Reverse(p1);
  cout<<endl;

  while(head!=NULL)
  { cout<<head->data;
    head=head->next;
  }

  return 0;
}
