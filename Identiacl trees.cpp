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

int identical(struct node* root,struct node* root1)
{
 if(root==NULL&&root1==NULL)
    return 1;
    if(root->data==root1->data)
        return identical(root->left,root1->left)&&identical(root->right,root1->right);
    else
        return 0;

}

int main()
{
   struct  node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->right = newnode(6);

    struct  node *root1 = newnode(1);
    root1->left = newnode(2);
    root1->right = newnode(3);
    root1->left->left = newnode(4);
    root1->left->right = newnode(5);
    root1->right->right = newnode(6);

    if(identical(root,root1))
    cout<<"identical"<<endl;






}






