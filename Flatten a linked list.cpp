#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* right;
    struct node* down;
};
void push (node** head_ref, int new_data)
{

   struct  node* new_node = (struct node *) malloc(sizeof(struct node));
    new_node->right = NULL;


    new_node->data  = new_data;


    new_node->down = (*head_ref);


    (*head_ref)    = new_node;
}
void printList(struct node *node)
{
  while (node != NULL)
  {
     cout<<node->data<<" ";
     node = node->down;
  }
  cout<<endl;
}
struct node* merge_list(struct node* head1,struct node* head2)
{
    struct node* head;
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    if(head1->data>head2->data){
        head=head2;
        head->down=merge_list(head1,head2->down);
        return head;
    }
    else{
        head=head1;
        head->down=merge_list(head1->down,head2);
        return head;

    }
};

struct node* flatten(struct node* head)
{

struct node* head1;
if(head==NULL||head->right==NULL)
    return head;
head1=merge_list(head,flatten(head->right));
return head;

};

int main()
{
    struct node* root= (struct node*)malloc(sizeof(struct node));
    push( &root, 30 );
    push( &root, 8 );
    push( &root, 7 );
    push( &root, 5 );

    push( &( root->right ), 20 );
    push( &( root->right ), 10 );

    push( &( root->right->right ), 50 );
    push( &( root->right->right ), 22 );
    push( &( root->right->right ), 19 );

    push( &( root->right->right->right ), 45 );
    push( &( root->right->right->right ), 40 );
    push( &( root->right->right->right ), 35 );
    push( &( root->right->right->right ), 20 );

    root=flatten(root);
    printList(root);





}



