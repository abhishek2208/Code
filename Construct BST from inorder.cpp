
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

// n*n Complexity

/*struct node*  construct(int a[],int l,int h)
{
    if(l>h)
        return NULL;


    struct node* root=newnode(a[l]);
    if(l==h)
        return root;

    int i;
    for( i=l+1;i<=h;i++)
    {
        if(a[i]>a[l])
            break;
    }

    root->left=construct(a,l+1,i-1);
    root->right=construct(a,i,h);

    return root;


}
void inorder(struct node* root)
{
    if(root==NULL)
        return ;


    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}*/

//n complexity
int index=0;
struct node* construct(int a[],int l,int h,int n)
{
    if(index>=n)
        return NULL;
        struct node* root=NULL;

    if(a[index]>=l&&a[index]<=h)
    {
         root=newnode(a[index++]);
        root->left=construct(a,l,root->data,n);
        root->right=construct(a,root->data,h,n);
    }


    return root;
};
void inorder(struct node* root)
{
    if(root==NULL)
        return ;


    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
     int a[] = {10, 5, 1, 7, 40, 50};
    int n = sizeof( a ) / sizeof( a[0] );

    struct node* root=NULL;
    root=construct(a,INT_MIN,INT_MAX,n);

inorder(root);;



}


