#include<iostream>
#include<climits>
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
    int N=(n*(n+1))/2;
    int arr[N];
    int sum=INT_MIN,h=0;
    for(int i=0;i<n;i>=0)
    {
        sum=0;
        for(int j=0;j<=i;j++)
      {
          sum+=a[j];
          arr[h]=sum;
          h++;
      }
    }
    for(int i=0;i<N-1;i++)
    {
        sum=max(arr[i],arr[i+1]);
    }
    cout<<sum<<endl;
    
    return 0;
}