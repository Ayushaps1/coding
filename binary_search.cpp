#include<iostream>
using namespace std;

int binary_search(int arr[],int n,int key){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    int k=binary_search(arr,n,key);
    if(k==-1)
        cout<<"given element is not presen in a given array";
    else
        cout<<"Given element is at index "<<k;
    return 0;
}