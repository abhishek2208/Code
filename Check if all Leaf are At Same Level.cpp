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
int getLevel(struct node* root)
{
    if(root==NULL)
        return 0;
    return 1+getLevel(root->left);
}
bool isSame(struct node* root,int d,int level)
{
   if(root==NULL)
   return true;
   if(level>d)
    return false;
   if(root->left==NULL&&root->right==NULL)
   {
       if (level==d)
        return true;

       return false;
   }


   return isSame(root->left,d,level+1)&&isSame(root->right,d,level+1);


}

int main()
{
    struct node* root=newnode(1);
     root->left = newnode(2);
     root->right= newnode(3);
     root->left->left = newnode(4);
     root->left->right= newnode(5);


     int d=getLevel(root);

    cout<<isSame(root,d,1)<<endl;



}





