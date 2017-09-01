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


void printpaths(struct node* root,int a[],int len)
{
   if(root->left==NULL&&root->right==NULL)
   {
       a[len]=root->data;
       len++;
       for(int i=0;i<len;i++)
        cout<<a[i]<<" ";

        cout<<endl;
       return ;
   }
   a[len]=root->data;

    if(root->left)
   printpaths(root->left,a,len+1);

   if(root->right)
   printpaths(root->right,a,len+1);

}


int main()
{
   struct  node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->right = newnode(6);


   int a[10];
    printpaths(root,a,0);





}









