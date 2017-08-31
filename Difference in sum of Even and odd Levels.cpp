#include<bits/stdc++.h>
using namespace std;

// Can be Done by Level Order Traversal
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
int difference(struct node* root)
{
   if(root==NULL)
   return 0;

   return root->data-difference(root->left)-difference(root->right);


}

int main()
{
    struct node* root=newnode(1);
     root->left = newnode(2);
     root->right= newnode(3);
     root->left->left = newnode(4);
     root->left->right= newnode(5);



    cout<<difference(root)<<endl;



}




