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
struct node* swap_node(struct node* head,int data1,int data2)
{
    if(data1==data2)
        return head;
    struct node* prevX=NULL;struct node* currX=head;
    struct node* prevY=NULL;struct node* currY=head;

    while(currX&&currX->data!=data1)
    {
        prevX=currX;
        currX=currX->next;
    }

    while(currY&&currY->data!=data2)
    {
        prevY=currY;
        currY=currY->next;
    }


    if(prevX==NULL)
           head=currY;
    else
        prevX->next=currY;



    if(prevY==NULL)
           head=currX;
    else
        prevY->next=currX;


struct node* temp=currX->next;
currX->next=currY->next;
currY->next=temp;


return head;

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
    head=swap_node(head,4,9);
    printList(head);


}

