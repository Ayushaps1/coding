#include<iostream>
#include<string>
using namespace std;

bool is_sorted(int a[],int n){
    
    if(n==1){
        return true;
    }

    bool restarray=is_sorted(a+1,n-1);
    return (a[0]<a[1] && restarray);
}

int main(){

    int a[]={1,2,3,4};
    cout<<is_sorted(a,5)<<endl;
    return 0;
}