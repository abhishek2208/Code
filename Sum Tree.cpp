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

    return root;
};

int sumTree(struct node* root)
{

 if(root==NULL)
    return 1;

  if(root->left==NULL&&root->right==NULL)
    return 1;

    int ls=0,rs=0;

  if(sumTree(root->left)&&sumTree(root->right))
  {
      if(root->left)
        {
        if(root->left->left==NULL&&root->left->right==NULL)
        ls=root->left->data;
        else
        ls=2*(root->left->data);
        }

      if(root->right)
        {
         if(root->right->left==NULL&&root->right->right==NULL)
         rs=root->right->data;
         else
         rs=2*(root->right->data);
      }

      if(root->data==ls+rs)
      return 1;

      else
        return 0;
  }
}

int main()
{
   struct  node*  root = newnode(14);
    root->left = newnode(3);
    root->right = newnode(4);
    root->left->left = newnode(1);
    root->left->right = newnode(2);
    root->right->right = newnode(4);

    int d=sumTree(root);
    cout<<d<<endl;






}






