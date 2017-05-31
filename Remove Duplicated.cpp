
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

void remove_duplicates(struct node* head)
{
    if(head==NULL)
        return;
        struct node* curr=head;
    while(curr->next!=NULL)
    {
        if(curr->data==curr->next->data)
        {
            struct node* temp=curr->next;
            curr->next=temp->next;
            free(temp);
        }
        else
            curr=curr->next;
    }

    return;

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
    head=append(head,6);
    head=append(head,8);
    head=append(head,8);

    printList(head);
    remove_duplicates(head);
    printList(head);







}



