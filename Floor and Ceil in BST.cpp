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
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
};
struct node* insertNode(struct node* root,int key)
{
    if(root==NULL)
     {
    struct node* temp=newnode(key);
    root=temp;
    return root;
     }
     if(root->data>key)
       root->left=insertNode(root->left,key);
     if(root->data<key)
        root->right=insertNode(root->right,key);

        return root;
};
 int Floor(struct node* root,int k)
{
    if(root==NULL)
        return INT_MAX;



    if(root->data>k)
        return Floor(root->left,k);

    int a=Floor(root->right,k);

    return a<k? a:root->data;
}

int  Ceil(struct node* root,int k)
{
    if(root==NULL)
        return -1;
    if(root->data==k)
        return root->data;

    if(root->data<k)
        return Ceil(root->right,k);
    int a=Ceil(root->left,k);
    return a>k? a:root->data;


}


int main()
{
    struct node* root=NULL;
    root=insertNode(root, 50);
    root=insertNode(root, 30);
    root=insertNode(root, 20);
    root=insertNode(root, 40);
    root=insertNode(root, 70);
    root=insertNode(root, 60);
    root=insertNode(root, 80);

    int d=Ceil(root,25);
    cout<<d<<endl;
      d=Floor(root,25);
    cout<<d<<endl;


}



