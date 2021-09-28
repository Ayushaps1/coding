#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main(){          // optimised sliding window maximum program
    int n,k;            // time complexity = O(n)
    cin>>n>>k;          // no of elements in ans for n and k will be =  n-k+1

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    deque<int> dq;      // deque or double ended queue
    vector<int> ans;

    for(int i=0;i<k;i++){
        while(!dq.empty() && (a[dq.back()] < a[i])){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(a[dq.front()]);

    for(int i=k;i<n;i++){
        if(dq.front() == i-k){
            dq.pop_front();
        }
        while(!dq.empty() && (a[dq.back()] < a[i])){
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(a[dq.front()]);
    }

    for(auto i:ans){
        cout<<i<<" ";
    }

    return 0;
}