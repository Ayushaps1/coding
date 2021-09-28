#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void computeNO(vector<int>arr,int k){  //Brute force approach
    pair<int,int>ans;                  //Time complexity = O(n^2)
    int sum = 0;
    bool found = 0;

    for(int i=0; i<(arr.size()-k); i++){
        sum = 0;
        for(int j=i; j<k; j++){
            sum += arr[j];
        }
        if(sum % 3 == 0){
            found = true;
            ans = make_pair(i,i+k-1);
            break;
        }
    }

    if(!found){
        cout<<"No such Subarray exits";
    }
    else{
        for(int i=ans.first; i<=ans.second; i++){
            cout<<arr[i]<<" ";
        }
    }
}

void computeNOfromSubarray(vector<int>arr,int k){   //optimised approach
    pair<int,int>ans;                               //Time complexity = O(n)    
    int sum = 0;
    bool found = false;

    for(int i=0; i<k; i++){
        sum += arr[i];
    }

    if(sum % 3 == 0){
        found = true;
        ans = make_pair(0,k-1);
    }

    for(int i=k; i<arr.size(); i++){
        if(found){
            break;
        }

        sum = sum + arr[i] - arr[i-k];
        if(sum % 3 == 0){
            found = true;
            ans = make_pair(i-k+1,i);
        }
    }

    if(!found){
        ans = make_pair(-1,0);
    }

    if(ans.first == -1){
        cout<<"Such subarray doesn't exist";
    }
    else{
        for(int i=ans.first; i<=ans.second; i++){
            cout<<arr[i]<<" ";
        }
    }
}

int main(){

    vector<int>arr = {1,23,5,6};
    int k = 2;

    //Brute force approach
    computeNO(arr,k);

    cout<<endl;
    
    //optimised approach
    computeNOfromSubarray(arr,k);

    return 0;
}