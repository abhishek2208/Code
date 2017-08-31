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
bool searchNode(struct node* root,int key)
{
    if(root==NULL)
        return false;
    if(root->data==key)
        return true;
    if(root->data>key)
    return searchNode(root->left,key);

     if(root->data<key)
    return searchNode(root->right,key);


}
struct node* deleteNode(struct node* root,int key)
{
    if(root==NULL)
        return root;

    if(root->data>key)
        root->left=deleteNode(root->left,key);
    else if(root->data<key)
        root->right=deleteNode(root->right,key);


        else
            {
                if(root->left==NULL&&root->right==NULL)
                {
                free(root);
                return NULL;
                }
               else  if(root->left==NULL)
                {
                    struct node* temp=root->right;
                    free(root);
                    return temp;
                }
                else if(root->right==NULL)
                {
                    struct node* temp=root->left;
                    free(root);
                    return temp;

                }
                else
                {
                    struct node* temp=root->right;
                    while(temp->left)
                        temp=temp->left;

                    root->data=temp->data;
                    root->right=deleteNode(root->right,temp->data);
                    return root;
                }
            }



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
    inorder(root);
    cout<<endl;

  cout<<searchNode(root,40)<<endl;

  root=deleteNode(root,50);

  inorder(root);
    cout<<endl;

}
