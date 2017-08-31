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
int maxValue(struct node* root)
{
    if(root==NULL)
        return INT_MIN;
    while(root->right)
        root=root->right;

    return root->data;
}
int minValue(struct node* root)
{
    if(root==NULL)
       return INT_MAX;
    while(root->left)
       root=root->right;

    return root->data;
}


bool isBST(struct node* root)
{
 if(root==NULL)
    return true;
 if(root->left&&maxValue(root->left)>root->data)
 return false;
 if(root->right&&minValue(root->right)<root->data)
    return false;

 if(isBST(root->left)&&isBST(root->right))
    return true;
 else
    return false;

}


int main()
{
    struct node* root=NULL;
    root=insertNode(root, 50);
    root=insertNode(root, 30);
    root=insertNode(root, 20);
    root=insertNode(root, 40);
    root=insertNode(root, 70);
    root=insertNode(root, 60);
    root=insertNode(root, 80);

    cout<<isBST(root)<<endl;



}


