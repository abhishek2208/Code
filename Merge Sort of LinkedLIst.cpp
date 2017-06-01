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
struct node* split(struct node* head)
{
    struct node* fast=head;
    struct node* slow=head;
    if(head==NULL)
        return NULL;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next;
        if(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
    struct node* temp;
    temp=slow->next;
    slow->next=NULL;
    return temp;
};
struct node* merge_list(struct node* head1,struct node* head2)
{
    struct node* head;
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    if(head1->data>head2->data){
        head=head2;
        head->next=merge_list(head1,head2->next);
        return head;
    }
    else{
        head=head1;
        head->next=merge_list(head1->next,head2);
        return head;

    }
};
struct node* merge_sort(struct node* head)
{
    struct node* head1;
    struct node* head2;
    struct node* headref;
    if(head->next==NULL)
        return head;
    struct node* mid;
   mid =split(head);
    head1=merge_sort(head);
    head2=merge_sort(mid);

    headref=merge_list(head1,head2);
    return headref;




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
    printList(head);
    struct node* head1;
    head1=merge_sort(head);

    printList(head);






}


