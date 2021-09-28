#include<iostream>
using namespace std;

void prime(int n){

    int a[n+1]={0};
    
    for(int i=2;i<=n;i++){
       
        if(a[i]==0){
          
            for(int j=i*i;j<=n;j+=i){
                
                 if(a[j]==0){
                  a[j]=1;
                }
            
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(a[i]==0)
            cout<<i<<" ";
    }
}

int main(){

    int n;
    cin>>n;

    prime(n);

    return 0;
}