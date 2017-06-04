#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newnode(int d)
{
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->data=d;
    root->left=NULL;
    root->right=NULL;
};

struct node* mirror(struct node* root)
{
 if(root==NULL)
    return root;
   root->left= mirror(root->left);
   root->right=mirror(root->right);
   struct node* temp=root->left;
   root->left=root->right;
   root->right=temp;
   return root;


}
void inOrder(struct node* node)
{
  if (node == NULL)
    return;

  inOrder(node->left);
  cout<<node->data<<" ";

  inOrder(node->right);
}


int main()
{
   struct  node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->right = newnode(6);


    inOrder(root);
    root=mirror(root);
    cout<<endl;
    inOrder(root);



}








