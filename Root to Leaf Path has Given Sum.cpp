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


int hasPath(struct node* root,int curr_sum,int sum)
{
 if(root==NULL)
    return 0;

    if(root->left==NULL&&root->right==NULL&&root->data+curr_sum==sum)
        return 1;


 return hasPath(root->left,root->data+curr_sum,sum)||hasPath(root->right,root->data+curr_sum,sum);
}

int main()
{
   struct  node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(3);
    root->left->right = newnode(5);
    root->right->right = newnode(6);


    int d=hasPath(root,0,7);
    cout<<d<<endl;






}







