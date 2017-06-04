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
void spiral(struct node* root,int level, bool val)
{
    if(root==NULL)
        return;

    if(level==1)
    {
        cout<<root->data<<" ";
    return ;
    }

    if(val)
    {
        spiral(root->left,level-1,val);
        spiral(root->right,level-1,val);

    }
    else
    {
        spiral(root->right,level-1,val);
         spiral(root->left,level-1,val);
    }



}


int main()
{
   struct  node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->right = newnode(6);


   int h=height(root);
   bool val=false;
   cout<<h<<endl;
   for(int i=1;i<=h;i++)
   {
    spiral(root,i,val);

    if(val)
        val=false;
    else
        val=true;
   }





}










