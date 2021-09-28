#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){

    int n,k;
    cin>>n>>k;

    vector<int> a(n);                       // for n ans will be n-k+1
    for(int i=0;i<n;i++){                   // time complexity O(nlogn)
        cin>>a[i];                          // we can optimise it by using deque
    }

    multiset<int,greater<int>> s;
    vector<int> ans;
    for(int i=0;i<k;i++){
        s.insert(a[i]);
    }
    ans.push_back(*s.begin());
    
    for(int i=k;i<n;i++){
        s.erase(s.find(a[i-k]));
        s.insert(a[i]);
        ans.push_back(*s.begin());
    }

    // this is also right
    // for(auto i : ans){
    //     cout<<i<<" ";
    // }

    for(int i=0;i<n-1;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}