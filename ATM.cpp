#include<iostream>
using namespace std;

int main()
{
    int x;
    float y,ans;
    cin>>x>>y;
    ans=y;
    if(x<5.50 || x>(y-0.50))
    {
        cout<<ans<<endl;
    }
    else
    {
        ans=y-x-0.50;
        cout<<ans<<endl;
    }
    
    return 0;
}