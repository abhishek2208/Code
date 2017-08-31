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


int balanced(struct node* root)
{
 if(root==NULL)
    return 1;


 return balanced(root->left)&&balanced(root->right)&&abs(height(root->left)-height(root->right))<2;
}

int main()
{
   struct  node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->left->right->left = newnode(8);
    root->left->right->left->left = newnode(9);
    root->right->right = newnode(6);


    int d=balanced(root);
    cout<<d<<endl;






}







