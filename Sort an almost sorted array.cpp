#include<bits/stdc++.h>
using namespace std;

void heapify(int a[],int n,int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int smallest=i;

    if(l<n&&a[l]<a[smallest])
        smallest=l;

    if(r<n&&a[r]<a[smallest])
        smallest=r;

    if(smallest!=i)
    {
        swap(a[i],a[smallest]);

        heapify(a,n,smallest);
    }


}
void deletekey(int a[],int n)
{
      swap(a[0],a[n-1]);

     heapify(a,n-1,0);



}
void insertkey(int a[],int n,int key)
{
    a[n-1]=key;
    int c=n-1;
    int p;



    while(c!=0)
    {
        if((n-1)%2==0)
        p=(n-1)/2-1;
        else
            p=(n-1)/2;

        if(a[p]>a[c])
            swap(a[c],a[p]);

            else break;

        c=p;
    }
}

int main()
{
    int a[] = {2, 6, 3, 12, 56, 8};
    int n=sizeof(a)/sizeof(a[0]);

   int k=3;
   int h[k+1];
   int s[n];
   int index=0;
   for(int i=0;i<k+1;i++)
   h[i]=a[i];

   for(int i=(k+1)/2;i>=0;i--)
    heapify(h,k+1,i);


    for(int i=k+1;i<n;i++)
    {
         s[index]=h[0];
  deletekey(h,k+1);
  index++;
  insertkey(h,k+1,a[i]);

    }
int si=k+1;
    for(int i=k+1;i>=0;i--)
    {

        s[index]=h[0];
  deletekey(h,si);
  si--;
  index++;


    }




    for(int i=0;i<n;i++)
        cout<<s[i]<<" ";



}

