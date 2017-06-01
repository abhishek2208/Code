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
struct node* reverse_list(struct node* head)
{
  if (head==NULL)
    return head;
  struct node* prev=NULL;
  struct node* curr=head;
  struct node* next;
  while(curr!=NULL)
  {
      next=curr->next;
      curr->next=prev;
      prev=curr;
      curr=next;
      }
      head=prev;

  return head;



};
struct node* delete_nodes(struct node* head)
{
    if(head==NULL)
        return head;
    struct node* head1=reverse_list(head);
    int maxm=head1->data;
    struct node* curr=head1;
    while(curr->next)
    {
        if(curr->next->data<maxm)
        {
             curr->next=curr->next->next;
        }
        else
        {
          maxm=max(maxm,curr->next->data);
          curr=curr->next;
        }
    }
    head1=reverse_list(head1);
    return head1;

};

int main()
{
    struct node* head= (struct node*)malloc(sizeof(struct node));
    head->data=4;
    head->next=NULL;
    head=append(head,5);
    head=append(head,6);
    head=append(head,7);
    head=append(head,8);
    head=append(head,9);
    printList(head);
    head=delete_nodes(head);
    printList(head);





}


