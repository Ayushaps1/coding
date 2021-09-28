#include<iostream>
#include<algorithm>  
using namespace std;

bool isfeasible(int mid,int a[],int n,int k){
    int pos = a[0];
    int element = 1;

    for(int i=1;i<n;i++){
        if(a[i]-pos >= mid){
            pos = a[i];
            element++;
        }
        if(element == k){
            return true;
        }
    }
    return false;
}

int largestminimumdistance(int a[],int n,int k){   // Binary search challenge   
    sort(a,a+n);
    int result = -1;
    int left =a[0];
    int right = a[n-1];
    while(left < right){
        int mid = (left+right)/2;
        if(isfeasible(mid,a,n,k)){
            left = mid+1;
            result = max(result,mid);
        }
        else{
            right = mid;
        }
    }
    return result;
}

int main(){

    int a[] = {1,2,8,4,9};  // 1,4,8 or 1,4,9
    int n = 5;
    int k = 3;

    cout<<"Largest minimum distance = "<<largestminimumdistance(a,n,k);

    return 0;
}