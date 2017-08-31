
#include<bits/stdc++.h>
using namespace std;
queue<struct node*>q;
struct node
{
    char data;
    struct node* left;
    struct node* right;
    struct node* eq;
    int endofString;
};
struct node* newnode(int d)
{
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->data=d;
    root->left=NULL;
    root->right=NULL;
    root->eq=NULL;
    root->endofString=0;

};


struct node* insertNode(struct node* root,char *a)
{
   if(root==NULL)
    root=newnode(*a);

    if(*a<root->data)
    root->left =insertNode(root->left,a);

   if(*a>root->data)
    root->right-insertNode(root->right,a);

    else
        {
            if(*(a+1))
            {
              root->eq=insertNode(root->eq,a+1);
            }
            else
                root->endofString=1;

    }

return root;


}void traverse(struct node* root,char* a,int depth)
{

    if(root==NULL)
        return;

        traverse(root->left,a,depth);

        a[depth]=root->data;
        if(root->endofString==1)
        {
            a[depth+1]='\0';
            cout<<a<<endl;
        }

         traverse(root->eq,a,depth+1);
          traverse(root->right,a,depth);



}



int main()
{

   struct node* root=NULL;
   char a[]="cats";

       root=insertNode(root,a);
       root=insertNode(root,"caps");
       root=insertNode(root,"bugs");

       char b[100];
       traverse(root,b,0);






}







