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
int maxValue(struct node* root)
{
    if(root==NULL)
        return INT_MIN;
    while(root->right)
        root=root->right;

    return root->data;
}
int minValue(struct node* root)
{
    if(root==NULL)
       return INT_MAX;
    while(root->left)
       root=root->right;

    return root->data;
}
// This Function Prints

/*int flag=0;
bool  lca(struct node* root,int key1,int key2)
{
  if(root==NULL)
  return false;

  if(root->data==key1||root->data==key2)
  return true;

  if(lca(root->left,key1,key2)&&lca(root->right,key1,key2))
  {
      if (flag==0)
      {
      cout<<root->data<<endl;
      flag=1;
      return true;
      }
      return true;

  }
  return lca(root->left,key1,key2)||lca(root->right,key1,key2);

}*/

//This Function returns

struct node* lca(struct node* root,int key1,int key2)
{
    if(root==NULL)
        return root;
    if(root->data>key1&&root->data>key2)
        return lca(root->left,key1,key2);
    if(root->data<key2&&root->data<key2)
        return lca(root->right,key1,key2);

    return root;

};

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

    cout<<lca(root,80,40)->data<<endl;



}



