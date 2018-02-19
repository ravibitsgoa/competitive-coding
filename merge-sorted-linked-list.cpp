#include<iostream>
/*
Merge two sorted lists A and B as one linked list
Node is defined as*/
struct Node
{ int data;
  struct Node *next;
};
Node* MergeLists (Node *headA, Node* headB)
{
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
  //head=Reverse(p1);
  cout<<endl;

  while(head!=NULL)
  { cout<<head->data;
    head=head->next;
  }

  return 0;
}
