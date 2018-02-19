#include<iostream>
using namespace std;
struct Node
{ int data;
  Node* left, *right;
};
bool checkBST(Node *root)
{ bool ans=1;
  cout<<root->data<<' ';
  if(root->left !=NULL && ((root->left->data) >= root->data))
    return 0;
  else if(root->left!=NULL)
    ans&=checkBST(root->left);
  if(root->right!=NULL && ((root->right->data) <= root->data))
    return 0;
  else if(root->right!=NULL)
    ans&=checkBST(root->right);
  cout<<ans<<endl;
  return ans;
}
int main()
{ Node n1, n2, n3, n4, n5, n6;
  n1.data=4; n1.left = &n2; n1.right = &n3;
  n2.data=3; n2.left = &n4; n2.right = &n5;
  n3.data=5; n3.left = &n6; n3.right = NULL;
  n4.data=2; n4.left = n4.right = NULL;
  n5.data=4; n5.left = n5.right = NULL;
  n6.data=4; n6.left = n6.right = NULL;
  cout<<checkBST(&n1);
return 0;
}
