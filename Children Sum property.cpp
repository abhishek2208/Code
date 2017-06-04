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


int height(struct node* root)
{
    if(root==NULL)
        return 0;

    return 1+max(height(root->left),height(root->right));
}
int check_childrensum(struct node* root)
{
    if(root==NULL)
        return 1;
    if(root->left==NULL&&root->right==NULL)
        return 1;
    int l=0;
    int r=0;
    if(root->left)
        l=root->left->data;
    if(root->right)
        r=root->right->data;

    if(l+r==root->data)
        return check_childrensum(root->left)&&check_childrensum(root->right);
        else
            return 0;





}
struct node* convert(struct node* root)
{
    if(root==NULL)
        return root;
    if(root->left==NULL&&root->right==NULL)
        return root;
    root->left=convert(root->left);
    root->right=convert(root->right);
    int l=0;
    int r=0;
    if(root->left)
        l=root->left->data;
    if(root->right)
        r=root->right->data;

        if(l+r==root->data)
            return root;
        else
            root->data=l+r;
        return root;



};
void preorder( struct node* root)
{
    if(root==NULL)
        return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
   struct  node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->right = newnode(6);


    int d=check_childrensum(root);
    if(d==1)
    cout<<"Chidren Sum Property Veified"<<endl;
   else{
        cout<<"Chidren Sum Property Not Veified and Converted tree preorder is"<<endl;
 root=convert(root);
 preorder(root);
 }








}











