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

bool ancestor(struct node* root,int key)
{
 if(root==NULL)
    return false;

 if(root->data==key)
    return true;

 if(ancestor(root->left,key)||ancestor(root->right,key))
    {
    cout<<root->data<<endl;
    return true;
    }
 else
    return false;;
}

int main()
{
   struct  node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->right = newnode(6);


    ancestor(root,4);







}






