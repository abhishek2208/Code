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

    return root;
};

int identical(struct node* root1,struct node* root2)
{

 if(root1==NULL&&root2==NULL)
    return 1;
 if(root1==NULL||root2==NULL)
    return 0;

 if(root1->data==root2->data)
    return identical(root1->left,root2->left)&&identical(root1->right,root2->right);
else
    return 0;

}
int subTree(struct node* root1,struct node* root2)
{

     if(root2==NULL)
        return 1;

     if(root1==NULL)
     return 0;
     if(identical(root1,root2))
        return 1;
     else
        return(subTree(root1->left,root2)||subTree(root1->right,root2));

}

int main()
{
   struct  node*  root = newnode(14);
    root->left = newnode(3);
    root->right = newnode(4);
    root->left->left = newnode(1);
    root->left->right = newnode(2);
    root->right->right = newnode(4);

    struct  node*  root1 = newnode(3);
    root1->left = newnode(1);
    root1->right = newnode(2);


    int d=subTree(root,root1);
    cout<<d<<endl;






}






