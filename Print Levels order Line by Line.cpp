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
void levelorder(struct node* root,int level)
{
 if(root==NULL)
    return ;
 if(level==1)
    {
        cout<<root->data<<" ";
        return;
    }
    levelorder(root->left,level-1);
    levelorder(root->right,level-1);


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
     for(int i=1;i<=h;i++)
     {
         levelorder(root,i);
         cout<<endl;
     }



}


