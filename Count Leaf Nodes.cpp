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
int countLeaf(struct node* root)
{
    if(root==NULL)
    return 0;
    if(root->left==NULL&&root->right==NULL)
    return 1;

    return countLeaf(root->left)+countLeaf(root->right);


}


int main()
{
   struct  node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->right = newnode(6);



    int c=countLeaf(root);
      cout<<c<<endl;




}










