#include<iostream>
using namespace std;

int searchInRotationArray(int a[],int key,int left,int right){
    if(left>right){
        return -1;
    }

    int mid = (left+right)/2;
    if(a[mid] == key){
        return mid;
    }

    if(a[left] < a[mid]){
        if(key >= a[left] && key <= a[mid]){
            return searchInRotationArray(a,key,left,mid-1);
        }
        return searchInRotationArray(a,key,mid+1,right);
    }

    if(key <= a[right] && key >= a[mid]){
        return searchInRotationArray(a,key,mid+1,right);
    }
    return searchInRotationArray(a,key,left,mid-1);
}

int main(){
    
    int a[] = {30,40,50,60,10,20};
    int key = 10;
    int n = 6;

    // testing
    int idx = searchInRotationArray(a,key,0,n-1);
    if(idx == -1){
        cout<<"key doesn't exist"<<endl;
    }
    else{
        cout<<"key is present at index = "<<idx<<endl;
    }

}