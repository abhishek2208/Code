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

struct node* head=NULL;
struct node* tail=NULL;
void convert(struct node* root)
{
    if(root==NULL)
     return;

     convert(root->left);

     if(head)
     {
         tail->right=root;
         root->left=tail;
         tail=root;}
         else
            {head=root;
            tail=root;
            }

            convert(root->right);

}
void Find_triplet(struct node* head,struct node* tail,int sum)
{
    if(head==NULL||head->right==NULL) return;
    while(head->right->right!=NULL)
    {
        struct node* l=head->right;
        struct node* r=tail;
        while(l!=r)
        {
            if(head->data+l->data+r->data==sum)
            {
                cout<<head->data<<" "<<l->data<<" "<<r->data<<endl;
                break;
            }
             if(head->data+l->data+r->data<sum)
            {
                l=l->right;
            }
             else if(head->data+l->data+r->data>sum)
            {
                r=r->left;
            }

        }
        head=head->right;


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

    convert(root);
    Find_triplet(head,tail,100);






}




