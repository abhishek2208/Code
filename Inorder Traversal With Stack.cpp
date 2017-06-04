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

void inorder(struct node* root)
{
 stack <struct node*> s;
 struct node* curr=root;

 while(1)
 {
     if(curr)
     {
        s.push(curr);
        curr=curr->left;
        }
        else
        {
            if(s.empty()==false){
            curr=s.top();
            s.pop();
            cout<<curr->data<<" ";
                curr=curr->right;}
                else
                    break;
            }

        }
}

int main()
{
   struct  node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->right = newnode(6);

    inorder(root);






}




