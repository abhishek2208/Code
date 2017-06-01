#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
struct node* append(struct node* head,int val)
{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=val;
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->next=NULL;
    return head;

}
void printList(struct node *node)
{
  while (node != NULL)
  {
     cout<<node->data<<" ";
     node = node->next;
  }
  cout<<endl;
}

struct node* invert(struct node* head ,int k)
{
    struct node* curr=head;
    struct node* prev=NULL;
    struct node* next_node;
    int c=0;

    if (head==NULL)
    return head;

    while(curr!=NULL&&c<k)
    {
        next_node=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next_node;
        c++;

            }


    head->next=curr;
    head=prev;

     c=0;

    while(curr!=NULL&&c<k-1)
    {
        curr=curr->next;
        c++;
    }

    if(curr!=NULL)
        curr->next=invert(curr->next,k);

return head;
};

int main()
{
    struct node* head= (struct node*)malloc(sizeof(struct node));
    head->data=4;
    head->next=NULL;
    head=append(head,10);
    head=append(head,6);
    head=append(head,12);
    head=append(head,8);
    head=append(head,9);
    printList(head);
    struct node* head1;
    head1=invert(head,2);
    printList(head1);






}



