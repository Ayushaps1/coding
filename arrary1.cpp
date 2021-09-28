#include <iostream>
using namespace std;

int main()
{
   int n,Max=-199999999;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
   {
      cin>>arr[i];
   }

   for(int i=0;i<n;i++)
   {
       Max=max(Max,arr[i]); 
   }
   cout<<"max = "<<Max<<endl;
   return 0;
}