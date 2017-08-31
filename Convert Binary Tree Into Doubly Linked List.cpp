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

struct node* prev;
int flag=0;
struct node* convert(struct node* root)
{
    if(root==NULL)
        return NULL;

       root->left=convert(root->left);
        if(prev)
         cout<<prev->data<<" ";
        if(flag==0)
        {

            prev=root;
            root->left=NULL;
            flag=1;


        }
        else
        {
          prev->right=root;
          root->left=prev;
          prev=root;


        }
        cout<<root->data<<endl;
     root->right=convert(root->right);

        return root;



}

int main()
{
    struct node* root=newnode(1);
     root->left = newnode(2);
     root->right= newnode(3);
     root->left->left = newnode(4);
     root->left->right= newnode(5);


     root=convert(root);
      while(root->left)
     {

         root=root->left;
     }

    while(root)
     {
         cout<<root->data<<" ";
         root=root->right;
     }






}



