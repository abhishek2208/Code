#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* next;
};
struct node* newnode(int d)
{
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->data=d;
    root->left=NULL;
    root->right=NULL;
    root->next=NULL;
};
int height(struct node* root)
{
    if(root==0)
        return 0;
    return 1+max(height(root->left),height(root->right));
}

static struct node* prev=newnode(0);
struct node* sucessor(struct node* root)
{
    if(root==NULL)
        return root;
    root->left=sucessor(root->left);
    prev->next=root;
    prev=root;

    root->right= sucessor(root->right);
    return root;

}

int main()
{
   struct  node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);


    root=sucessor(root);
    while(root->left!=NULL)
        root=root->left;

    while(root!=NULL)
    {
        cout<<root->data<<" ";
        root=root->next;
    }










}








