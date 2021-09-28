#include<iostream>
using namespace std;

int searchPeakElement(int a[],int n,int start,int end){

    int mid = start + (end - start)/2;
    if((mid == 0 || a[mid] >= a[mid-1]) && (mid == n-1 || a[mid] >= a[mid+1])){
        return mid;
    }
    else if(mid>0 && a[mid-1] <= a[mid]){
        return searchPeakElement(a,n,start,mid-1);
    }
    else{
        return searchPeakElement(a,n,mid+1,end);
    }
}

int main(){

    int a[] = {0,6,8,9,10,12,11};
    int n = 6;

    // finding peak element
    cout<<"Peak element = "<<searchPeakElement(a,n,0,n-1)<<endl;    

    return 0;
}