#include<bits/stdc++.h>
using namespace std;
queue<struct node*>q;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct Node
{
    int data;
   struct Node* next;
};
struct Node* newNode(int d)
{
     struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
     temp->data=d;
     temp->next=NULL;
     return temp;
};
struct node* newnode(int d)
{
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->data=d;
    root->left=NULL;
    root->right=NULL;
    return root;
};


struct node* buildTree(struct node* root,struct Node* node)
{
     struct node* temp=(struct node*)malloc(sizeof(struct node));
     temp=newnode(node->data);

     if(root==NULL)
        {
        root=temp;
        q.push(temp);
        return root;
        }


     if(q.front()->left==NULL)
        q.front()->left=temp;
     else if(q.front()->right==NULL)
        q.front()->right=temp;

     if(q.front()->left&&q.front()->right)
        q.pop();

     q.push(temp);

     return root;


}



int main()
{

   struct node* root=NULL;
   struct Node* head=newNode(1);
   head->next=newNode(2);
   head->next->next=newNode(3);
   head->next->next->next=newNode(4);
   head->next->next->next->next=newNode(5);

   while(head!=NULL)
       {
           root=buildTree(root,head);
           head=head->next;
       }
 cout<<root->data<<endl;
   cout<<root->left->data<<endl;
   cout<<root->right->data;


   }












