#include<bits/stdc++.h>
using namespace std;
queue<struct node*>q;
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


struct node* buildTree(struct node* root,int i)
{
     struct node* temp=(struct node*)malloc(sizeof(struct node));
     temp=newnode(i);

     if(root==NULL)
        {
        root=temp;
        q.push(temp);
        return root;
        }


     if(q.front()->left==NULL)
        q.front()->left=temp;
     else if(q.front()->right==NULL)
        q.front()->right=temp;

     if(q.front()->left&&q.front()->right)
        q.pop();

     q.push(temp);

     return root;


}



int main()
{

   struct node* root=NULL;
   for(int i=0;i<12;i++)
   {
       root=buildTree(root,i);

   }
cout<<root->right->data;


}







