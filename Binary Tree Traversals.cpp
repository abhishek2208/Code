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
void inorder(struct node* root)
{
    if(root==NULL)
        return ;


    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(struct node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);

    preorder(root->right);
}
void postorder(struct node* root)
{
    if(root==NULL)
        return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
}
int main()
{
    struct node* root=newnode(1);
     root->left = newnode(2);
     root->right= newnode(3);
     root->left->left = newnode(4);
     root->left->right= newnode(5);

     inorder(root);
     cout<<endl;
     preorder(root);
     cout<<endl;
     postorder(root);
     cout<<endl;

}
