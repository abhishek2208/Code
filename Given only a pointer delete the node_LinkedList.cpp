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
void delete_node(struct node* ptr)
{
    struct node* temp=ptr->next;
    ptr->data=temp->data;
    ptr->next=temp->next;
    free(temp);
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
    printList(head);
    delete_node(head->next);
    printList(head);





}


