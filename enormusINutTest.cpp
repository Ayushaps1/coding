#include<iostream>
using namespace std;

int main()
{
   int n,k,ans=0;
   int a[n];
   cin>>n>>k;
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }

    for(int i=0;i<n;i++)
    {
        if(a[i]%k==0)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
   return 0;
}