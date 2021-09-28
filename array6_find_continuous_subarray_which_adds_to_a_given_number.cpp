#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int s;
    cin>>s;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int st=0,end=0,curr_sum=a[st];;
    for(int i=0;i<n;i++)
    {
        if(curr_sum<s)
        {
            end++;
            curr_sum+=a[end];
        }
        else if(curr_sum>s)
        {
            st++;
            curr_sum-=a[st-1];
        }
        else
        {
            break;
        }
    }
    
    if(st==0 && end==0)
    {
        cout<<"-1";
    }
    else
    {
        cout<<st+1<<" "<<end+1<<endl;
    }
    return 0;
}5