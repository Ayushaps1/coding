#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int smallsubarray(int a[],int n,int x){    //brute force approach 
    int ans = INT_MAX,sum = 0;             //Time complexity = O(n^2)

    for(int i = 0;i<n;i++){
        sum = 0;
        for(int j = i;j<n;j++){
            sum += a[i];
            if(sum > x){
                ans = min(ans,j-i+1);
            }
        }
    }

    return ans;

}

int smallestSubarraywithSum(int a[],int n,int x){       //Time complexity = O(n)
    int sum = 0,minlength = n+1,start = 0,end = 0;      
    while(end < n){
        while(sum <= x && end < n){
            sum += a[end++];A
        }

        while(sum > x && start < n){
            if(end-start < minlength){
                minlength = end-start;
            }
            sum -= a[start++];
        }
    }
    return minlength;
}

int min_subarray(int a[],int n,int x){    //Time complexity = o(n);
                                          // my solution approach
    int ans = INT_MAX,sum = 0;        
    int i = 0;
    int start = 0;
    while(i<=n){
        if (sum > x){
            ans = min(ans,i-start);
            sum -= a[start];
            start++;
        }
        else{
            sum += a[i];
            i++;
        }
    }

    return ans;
}

int main(){

    int a[] = {2,3,4,5};
    int x = 4;
    int n = 4;
    // optimised approach
    cout<<min_subarray(a,n,x)<<endl;
    
    // same as above but a bit difference in code
    int minlength = smallestSubarraywithSum(a,n,x);

    if(minlength == n+1){
        cout<<"No such subarray exits"<<endl;
    }
    else{
        cout<<"smallest length subarray is : "<<minlength<<endl;
    }

    //brute force approach 
    cout<<smallsubarray(a,n,x)<<endl;

    return 0;
}