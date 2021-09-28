
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int arr[N];
    for(int i =0;i<N;i++)
    {
        cin>>arr[i];
    }

    int pd=arr[1]-arr[0];
    int curr_len=2;
    int ans=2;
    for(int i=2;i<N;i++)
    {
        if(pd == arr[i]-arr[i-1])
        {
            curr_len++;
        }
        else
        {
            pd=arr[i]-arr[i-1];
            curr_len=2;
        }
        ans=max(ans,curr_len); 
    }
    cout<<"maximum length = "<<ans<<endl;
    return 0;
}