/*isayyana is given the number of visitors*/

#include <iostream>
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
    arr[n]=-1;
    int prev_max=-1999999;
    int break_days=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]>prev_max && arr[i]>arr[i+1])
        {
            break_days++;
        }
        
        prev_max=max(prev_max,arr[i]);
    }
    cout<<"Total number of record breaking days = "<<break_days<<endl;

    return 0;
}