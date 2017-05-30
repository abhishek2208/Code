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
void  remove_loop(struct node* ptr,struct node* head)
{
    struct node* ptr1;
    struct node* ptr2;
    ptr1=head;
    while(1)
    {
        ptr2=ptr;
        while(ptr2->next!=ptr&&ptr2->next!=ptr1)
        {
            ptr2=ptr2->next;
            }

            if(ptr2->next==ptr1)
                {
                ptr2->next=NULL;
                return;
                }
                ptr1=ptr1->next;
    }
    return;

}
void  detect_loop(struct node* head)
{
  if (head==NULL)
    return;

  struct node* fast_ptr=head;
  struct node* slw_ptr=head;
  while(slw_ptr&&fast_ptr&&fast_ptr->next)
  {
      fast_ptr=fast_ptr->next->next;
      slw_ptr=slw_ptr->next;
      if(fast_ptr==slw_ptr)
      {
          remove_loop(slw_ptr,head);
          break;
      }
  }
  return ;
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
    head->next->next->next->next->next->next=head;
    detect_loop(head);
    printList(head);






}

