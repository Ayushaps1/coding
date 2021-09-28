#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
       { 
         if(a[i]>(ans+1))
         {
            ans=ans+1;
            break;
         }
         else
         {
             ans=a[i];
         }
       }
    }
    if(ans==0)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }
   return 0;
}