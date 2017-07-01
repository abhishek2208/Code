#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int part(int a[],int l,int h)
{
   int piv=a[h];

   int i=l;

   for(int j=l;j<=h-1;j++)
   {
       if(a[j]<=piv)
       {
           swap(&a[j],&a[i]);
           i++;

       }
   }
   swap(&a[i],&a[h]);

   return i;

}
void quicksort(int a[],int l,int h)
{
    if(l<h)
    {
        int pi=part(a,l,h);

        quicksort(a,l,pi-1);
        quicksort(a,pi+1,h);
    }
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    quicksort(a,0,n-1);

    for(int i=0;i<n;i++)
        cout<<a[i]<<endl;
}
