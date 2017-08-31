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
int isomorph(struct node* root1, struct node* root2)
{
    if(root1==NULL&&root2==NULL)
        return 1;

      if(root1->data!=root2->data)
        return 0;

      if(root1==NULL||root2==NULL)
        return 0;

      return (isomorph(root1->left,root2->left)&&isomorph(root1->right,root2->right))||(isomorph(root1->left,root2->right)&&isomorph(root1->right,root2->left));

}

int main()
{
    struct node* root=newnode(1);
     root->left = newnode(2);
     root->right= newnode(3);
     root->left->left = newnode(4);
     root->left->right= newnode(5);

      struct node* root1=newnode(1);
     root1->left = newnode(3);
     root1->right= newnode(2);
     root1->right->left = newnode(4);
     root1->right->right= newnode(5);


    cout<<isomorph(root,root1)<<endl;



}



