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
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
};
struct node* insertNode(struct node* root,int key)
{
    if(root==NULL)
     {
    struct node* temp=newnode(key);
    root=temp;
    return root;
     }
     if(root->data>key)
       root->left=insertNode(root->left,key);
     if(root->data<key)
        root->right=insertNode(root->right,key);

        return root;
};
void storeInorder(struct node* root, int a[], int* i)
{
    if(root==NULL)
        return;

    storeInorder(root->left,a,i);

    a[*i]=root->data;
     (*i)++;


    storeInorder(root->right,a,i);
}
struct node* construct(struct node* root,int a[],int *j)
{
    if(root==NULL)
        return root;
        root->left=construct(root->left,a,j);

        root->data=a[*j];
        (*j)++;

        root->right=construct(root->right,a,j);

};
void inorder(struct node* root)
{
    if(root==NULL)
        return ;


    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main()
{
    struct node* root=NULL;
    root = newnode(10);
    root->left = newnode(30);
    root->right = newnode(15);
    root->left->left = newnode(20);
    root->right->right = newnode(5);

    int *a=new int[5];
    int i=0;
    storeInorder(root,a,&i);

    sort(a,a+5);
    int j=0;
    root=construct (root,a,&j);
    inorder(root);



}




