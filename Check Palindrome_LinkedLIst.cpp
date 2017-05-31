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
void check(struct node* head)
{
    stack< struct node*> s;
    struct node* temp=head;
    int flag=0;
    while(temp!=NULL)
    {
        s.push(temp);
        temp=temp->next;
    }
    temp=head;
    while(temp&&temp->data==s.top()->data)
    {
        s.pop();
        temp=temp->next;
    }
    if(temp==NULL)
        cout<<"Palindrome"<<endl;
    else
        cout<<"Not"<<endl;


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
    head=append(head,5);
    head=append(head,4);
    printList(head);
    check(head);






}



