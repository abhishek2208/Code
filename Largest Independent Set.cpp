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
int liss(struct node* root)
{
    if(root==NULL)
        return 0;

        int val_inc=1;
        int val_exc=0;
        if(root->left)
            val_inc+=liss(root->left->left)+liss(root->left->right);
        if(root->right)
            val_inc+=liss(root->right->left)+liss(root->right->right);

        val_exc=liss(root->left)+liss(root->right);

    return max(val_exc,val_inc);

}

int main()
{
    struct node* root=newnode(1);
     root->left = newnode(2);
     root->right= newnode(3);
     root->left->left = newnode(4);
     root->left->right= newnode(5);


    cout<<liss(root)<<endl;



}


