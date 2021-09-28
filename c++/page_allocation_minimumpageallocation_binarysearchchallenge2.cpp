#include<iostream>
#include<climits>
using namespace std;

bool ispossible(int a[],int n,int m,int Min){
    int studentsrequired = 1;
    int sum = 0;

    for(int i = 0; i<n; i++){
        if(a[i] > Min){
            return false;
        }

        if(sum+a[i] > Min){
            studentsrequired++;
            sum = a[i];
        
            if(studentsrequired > m){
                return false;
            }
        }
        else{
            sum += a[i];
        }
        
    }
    return true;
}

int allocateminiumpages(int a[],int n,int m){
    int sum = 0; 
    int ans = INT_MAX;
    if(n < m){
        return -1;
    }
    
    for(int i = 0; i < n; i++){
        sum += a[i];
    }

    int start = a[0]; 
    int end = sum;

    while(start <= end){
        int mid = (start+end)/2;
        if(ispossible(a,n,m,mid)){
            ans = min(ans,mid);
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main(){

    int a[] = {20,34,60,80};
    int n = 4;
    int m = 2;

    cout<<"The minimum no. of pages : "<<allocateminiumpages(a,n,m)<<endl;

    return 0;
}