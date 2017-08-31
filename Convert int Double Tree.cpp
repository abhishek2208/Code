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
    if(root==0)
        return 0;
    return 1+max(height(root->left),height(root->right));
}

void inorder(struct node* root)
{
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
struct node* Double(struct node* root)
{

    if(root==NULL)
        return root;

    root->left=Double(root->left);
    root->right=Double(root->right);

    struct node* temp=root->left;
     struct node* new_node=(struct node*)malloc(sizeof(struct node));

     new_node->data=root->data;

     new_node->left=temp;
     new_node->right=NULL;
     root->left=new_node;

     return root;


}

int main()
{
   struct  node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->right = newnode(6);


     root=Double(root);
     inorder(root);







}







