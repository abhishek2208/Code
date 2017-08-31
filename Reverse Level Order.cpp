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
{ if(root==NULL)
return 0;

return 1+max(height(root->left),height(root->right));

}
void reverseLevelorder(struct node* root, int level)
{
    if(root==NULL)
        return;

    if(level==1)
        cout<<root->data<<" " ;

  reverseLevelorder(root->left,level-1);
  reverseLevelorder(root->right,level-1);


}

int main()
{
    struct node* root=newnode(1);
     root->left = newnode(2);
     root->right= newnode(3);
     root->left->left = newnode(4);
     root->left->right= newnode(5);


   int h=height(root);
   for(int i=h;i>=1;i--)
   {
       reverseLevelorder(root,i);
   }


}



