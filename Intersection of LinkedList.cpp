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
int _count(struct node* head)
{
    int c=0;
    while(head!=NULL)
    {
        c++;
        head=head->next;
    }
    return c;
}

void intersection(struct node* head1,struct node* head2)
{
    int c1=_count(head1);
    int c2=_count(head2);
    int d=abs(c1-c2);
    struct node* temp1=head1;
    struct node* temp2=head2;
    if(c1>c2)
    {
        while(d){
            temp1=temp1->next;
            d--;}

    }
    else
    {
        while(d){
            temp2=temp2->next;
            d--;
        }
    }
    while(temp1&&temp2&&temp1!=temp2)
    {
        temp1=temp1->next;
        temp2=temp2->next;
    }
    cout<<temp2->data<<endl;
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
    struct node* head1= (struct node*)malloc(sizeof(struct node));
    head1->data=10;
    head1->next=NULL;
    head1=append(head1,11);
    head1->next->next=head->next;
    printList(head);
    printList(head1);
    intersection(head,head1);





}



