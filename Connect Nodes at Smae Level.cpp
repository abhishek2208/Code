#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* next;
};
struct node* newnode(int d)
{
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->data=d;
    root->left=NULL;
    root->right=NULL;
    root->next=NULL;

    return root;
};


void connect(struct node* root)
{
  queue< pair< struct node*,int> > q;

  q.push(make_pair(root,1));

   pair< struct node*,int> prev;
    pair< struct node*,int> n;
    prev=q.front();

  while(q.empty()==false)
  {

      q.pop();

      if(prev.first->left)
      q.push(make_pair(prev.first->left,prev.second+1));

      if(prev.first->right)
      q.push(make_pair(prev.first->right,prev.second+1));

       if(q.empty()==true)
       prev.first->next=NULL;
       else {
            n=q.front();
            if(prev.second==n.second)
            prev.first->next=n.first;
            else
                 prev.first->next=NULL;

            }

      prev=n;

  }
}

int main()
{
   struct  node*  root = newnode(14);
    root->left = newnode(3);
    root->right = newnode(4);
    root->left->left = newnode(1);
    root->left->right = newnode(2);
    root->right->right = newnode(4);




    connect(root);
    cout<<root->left->next->data<<endl;
    cout<< root->left->left->next->data<<endl;






}







