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
struct node* mirror(struct node* root)
{
 if(root==NULL)
    return root;
   root->left= mirror(root->left);
   root->right=mirror(root->right);
   struct node* temp=root->left;
   root->left=root->right;
   root->right=temp;
   return root;


}
int isSame(struct node* root1,struct node* root2)
{
    if(root1==NULL&&root2==NULL)
        return 1;

    if(root1&&root2)
        return isSame(root1->left,root2->left)&&isSame(root1->right,root2->right);
    else
        return 0;
}

int foldable(struct node* root)
{
    if(root==NULL)
        return 1;

    root->left=mirror(root->left);

    int d=isSame(root->left,root->right);
    return d;

}

int main()
{
   struct  node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);



    int d=foldable(root);
    cout<<d<<endl;






}







