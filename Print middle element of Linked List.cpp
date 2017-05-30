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
void middle(struct node* head)
{
   struct node* fast_ptr=head;
   struct node* slw_ptr=head;

   if(head==NULL)
    return;
    else{

   while( fast_ptr!=NULL && fast_ptr->next!=NULL)
   {
       fast_ptr=fast_ptr->next->next;
       slw_ptr=slw_ptr->next;
   }
   cout<<slw_ptr->data<<endl;
   return;
   }



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
    middle(head);





}

