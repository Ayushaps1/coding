#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//Time complexity to check if n is palindrome is O(n)
// O(n) because in worst case k can be equal to n
bool ispalindrom(int n){
    int temp=n,revn=0;

    while(temp > 0){
        revn = revn*10 + temp%10;
        temp /= 10;
    }

    if(revn == n){
        return true;
    }
    return false;
}

int FindpalindromicSubarray(vector<int>arr,int k){  //optimised approach
    int num = 0;                                   //Time complexity = O(n^2)
         
    for(int i=0; i<k; i++){
        num = num*10+arr[i];
    }

    if(ispalindrom(num)){
        return 0;
    }

    for(int i=k; i<arr.size(); i++){
        num = (num % (int)pow(10,k-1))*10+arr[i];
        if(ispalindrom(num)){
            return i-k+1;
        }
    }

    return -1;
}

int main(){

    vector<int>arr = {2,3,4,5,1,1,5};
    int k = 4;
    
    // for brute force approach Time complexity would be O(n^3) 

    // optimisied approach
    int ans = FindpalindromicSubarray(arr,k);

    if(ans == -1){
        cout<<"Palindromic subarray doesn't exist"<<endl;
    }
    else{
        for(int i=ans; i<ans+k; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}