#include<iostream>
using namespace std;

int fibonacci1(int n){
    if(n == 0 || n == 1){
        return n;
    }
    
    int ans = fibonacci1(n-1)+fibonacci1(n-2);
    return ans;
}

int fibonacci2(int n,int a[]){
    if(n == 0 || n ==1){
        return n;
    }

    if(a[n]!=0){
        return a[n];
    }

    int ans = fibonacci2(n-1,a)+fibonacci2(n-2,a);
    a[n] = ans;

    return a[n];
}

int fibonacci3(int n,int a[]){
    a[0]=0;
    a[1]=1;

    for(int i=2;i<=n;i++){
        a[i] = a[i-1]+a[i-2];
    }
    return a[n];
}

int fibonacci4(int n){
    int a1 = 0;
    int a2 = 1;

    for(int i=2;i<=n;i++){
        int temp = a1+a2;
        a1 = a2;
        a2 = temp;
    }
    return a2;
}


int main(){

    int n;
    cin>>n;
    int a[n+1] = {0};
    
    cout<<fibonacci1(n)<<endl;
    // 0 1 1 2 3 5 8 13 21 12
    cout<<fibonacci2(n,a)<<endl;
    cout<<fibonacci3(n,new int[n+1]{0})<<endl;
    cout<<fibonacci4(n)<<endl;


    return 0;
}