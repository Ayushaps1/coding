#include<iostream>
using namespace std;

int isPerfectNumber(int n){
    int ans = 0;

    
}

int maxSum(int a[],int n,int k){
    if(n < k){
        cout<<"Invalid values"<<endl;
        return -1;
    }

    int result = 0;
    
    for(int i=0; i<k; i++){
        result += a[i];
    }

    int sum = res;
    for(int i=k; i<n; i++){
        sum += (a[i] - a[i-k]);
        result = max(result,sum);
    }

    return result;
}

int maxPerfectNumberinsubarray(int a[],int n,int k){
    for(int i = 0; i<n; i++){
        if(isPerfectNumber(a[i])){
            a[i] = 1;
        }
        else{
            a[i] = 0;
        }
    }

    return maxSum(a,n,k);
}

int main(){



    return 0;
}