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


int diameter(struct node* root)
{
 if(root==NULL)
    return 0;


 return max(max(diameter(root->left),diameter(root->right)),1+height(root->left)+height(root->right));
}

int main()
{
   struct  node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->right = newnode(6);


    int d=diameter(root);
    cout<<d<<endl;






}






