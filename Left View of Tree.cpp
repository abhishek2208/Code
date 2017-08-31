#include<bits/stdc++.h>
using namespace std;
int Max=0;
struct node
{
    int data;
    int hd;
    struct node* left;
    struct node* right;

};
struct node* newnode(int d)
{
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->data=d;
    root->left=NULL;
    root->right=NULL;
};
void leftView(struct node* root,int level)
{
   if(root==NULL)
   return ;

   if(level>Max)
   {
       cout<<root->data<<" ";
       Max=level;
   }

   leftView(root->left,level+1);
   leftView(root->right,level+1);


}
void rightView(struct node* root,int level)
{
     if(root==NULL)
   return ;

   if(level>Max)
   {
      cout<<root->data<<" ";
       Max=level;
   }

   rightView(root->right,level+1);
   rightView(root->left,level+1);


}
void bottomView(struct node* root)
{
    map <int, int> m;
    queue <struct node* > q;
    if(root==NULL)
        return;

    root->hd=0;
    q.push(root);
    while(!q.empty())
    {
       if(q.front()->left)
       {
           q.front()->left->hd=q.front()->hd-1;
           q.push(q.front()->left);
       }
       if(q.front()->right)
       {
           q.front()->right->hd=q.front()->hd+1;
           q.push(q.front()->right);
       }
       m[q.front()->hd]=q.front()->data;
       q.pop();

       }

      for (map<int,int>::iterator i = m.begin(); i != m.end(); ++i)
      cout << i->second << " ";

    }

void topView(struct node* root)
{
    map <int, int> m;
    queue <struct node* > q;
    if(root==NULL)
        return;

    root->hd=0;
    q.push(root);
    while(!q.empty())
    {
       if(q.front()->left)
       {
           q.front()->left->hd=q.front()->hd-1;
           q.push(q.front()->left);
       }
       if(q.front()->right)
       {
           q.front()->right->hd=q.front()->hd+1;
           q.push(q.front()->right);
       }
       if(!m[q.front()->hd])
       m[q.front()->hd]=q.front()->data;

       q.pop();

       }

      for (map<int,int>::iterator i = m.begin(); i != m.end(); ++i)
      cout << i->second << " ";

    }







int main()
{
    struct node* root=newnode(1);
     root->left = newnode(2);
     root->right= newnode(3);
     root->left->left = newnode(4);
     root->left->right= newnode(5);



    leftView(root,1);
    cout<<endl;
    Max=0;
    bottomView(root);
    cout<<endl;
    rightView(root,1);
    cout<<endl;
    topView(root);



}





