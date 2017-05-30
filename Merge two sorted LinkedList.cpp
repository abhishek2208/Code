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

int main()
{
    struct node* head= (struct node*)malloc(sizeof(struct node));
    struct node* head1= (struct node*)malloc(sizeof(struct node));
    head->data=4;
    head->next=NULL;
    head=append(head,5);
    head=append(head,6);
    head=append(head,12);
    head=append(head,13);
    head=append(head,14);

    head1->data=3;
    head1->next=NULL;
    head1=append(head1,7);
    head1=append(head1,8);
    head1=append(head1,9);
    head1=append(head1,10);
    head1=append(head1,15);
    printList(head);
    printList(head1);
    head=merge_list(head,head1);
    printList(head);






}

