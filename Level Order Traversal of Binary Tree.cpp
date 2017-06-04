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
void levelorder(struct node* root)
{
    queue<struct node*> q;
    q.push(root);

    while(q.empty()!=true)
    {
        cout<<q.front()->data<<" ";
        if(q.front()->left)
        q.push(q.front()->left);
        if(q.front()->right)
        q.push(q.front()->right);
        q.pop();

    }
}

int main()
{
    struct node* root=newnode(1);
     root->left = newnode(2);
     root->right= newnode(3);
     root->left->left = newnode(4);
     root->left->right= newnode(5);


     levelorder(root);



}

