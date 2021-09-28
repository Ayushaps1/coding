#include <iostream>
#include<limits.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    const int N=1e6+2;
    int arr1[N];
    for(int i=0;i<N;i++)
    {
        arr1[i]=-1;
    }

    int minidx =INT_MAX;  
    for(int i=0;i<n;i++)
    {
        if(arr1[arr[i]]!=-1)
        {
            minidx=min(minidx,arr1[arr[i]]);
        }
        else
        {
            arr1[arr[i]]=i;
        }
    }
    if(minidx==INT_MAX)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<minidx+1<<endl;
    }
    return 0;    
}