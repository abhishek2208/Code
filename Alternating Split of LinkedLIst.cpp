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
void split(struct node* head ,struct node** a,struct node** b)
{
    struct node* curr=head;
    struct node* curr1;
    struct node* curr2;

    if(head==NULL)
    {
        *a=NULL;
        *b=NULL;
        return;

    }

    *a=head;
    *b=head->next;

    curr2=*b;
    curr1=*a;

    curr=curr->next->next;

    while(curr)
    {
       curr1->next=curr;
       if(curr->next!=NULL)
       curr2->next=curr->next;
       else
       {
         curr2->next=NULL;
         curr1->next->next=NULL;
         return;
       }
       curr=curr->next->next;
       curr1=curr1->next;
       curr2=curr2->next;

    }
    curr1->next=NULL;
    curr2->next=NULL;








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
    printList(head);
    struct node* a=NULL;
    struct node* b=NULL;
    split(head,&a,&b);
    printList(a);
    printList(b);





}


