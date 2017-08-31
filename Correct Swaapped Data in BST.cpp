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


struct node* first=NULL;
struct node* middle=NULL;
struct node* last=NULL;
struct node* prev=NULL;

void correct(struct node* root)
{
    if(root==NULL)
        return;

    correct(root->left);


    if(!prev)
        prev=root;

     else if(prev->data>root->data)
        {
      if(!first)
       {
        first=prev;
        middle=root;
       }
       else
        last=root;

        }
        prev=root;
        correct(root->right);
}

void inorder(struct node* root)
{
    if(root==NULL)
        return ;


    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
     struct node *root = newnode(6);
    root->left        = newnode(10);
    root->right       = newnode(2);
    root->left->left  = newnode(1);
    root->left->right = newnode(3);
    root->right->right = newnode(12);
    root->right->left = newnode(7);

correct(root);

//cout<<first->data<<endl;

    if(first&&last)
    swap(&(first->data),&(last->data));
    else if(first && middle)
        swap(&(first->data),&(middle->data));

inorder(root);




}



