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
void inorder(struct node* root)
{
    if(root==NULL)
        return ;


    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
struct node* pre=NULL;
struct node* suc=NULL;

void Find(struct node* root,int key)
{
  if(root==NULL)
    return;
  if(root->data==key)
  {
      if(root->left!=NULL)
      {
          struct node* temp=root->left;
          while(temp->right)
           temp=temp->right;

           pre=temp;
      }
      if(root->right!=NULL)
      {
          struct node* temp=root->right;
          while(temp->left)
           temp=temp->left;

           suc=temp;

      }

      return;
  }
  else if(root->data>key)
  {
      suc=root;
      Find(root->left,key);


  }
  else if(root->data<key)
  {
      pre=root;
      Find(root->right,key);
  }

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

    Find(root,40);
    cout<<pre->data<<endl;
    cout<<suc->data<<endl;


}

