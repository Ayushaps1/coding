//Program to find maximum numbers of consecutive one's
#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int max_cons1(vector<int>v,int n,int k){   //Time complexity = O(n)
    int i = 0;
    int zerocount = 0;
    int ans = INT_MIN;

    for(int j=0;j<n;j++){
        if(v[j] == 0){
            zerocount++;
        }
        while(zerocount > k){
            if(v[i] == 0){
                zerocount--;
            }
            i++;
        }
        ans = max(ans,j-i+1);
    }

    return ans;
}

int main(){

    int n,k;
    cin>>n>>k;

    vector<int> v(n);
    for(auto &i:v){
        cin>>i;
    }

    //finding maximum no of consicutive 1's
    cout<<"Maximum no of consicutive one's = "<<max_cons1(v,n,k)<<endl;

    return 0;
}