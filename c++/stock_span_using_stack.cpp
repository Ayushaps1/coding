// Program to find span of stocks price of each day
// Span of stocks price is = "span is the maximum consicutive days (from today ans then backward to the first day)
// for which stock prices are less than or equal to todays stock price"
#include<iostream>
#include<stack>
#include<vector>
#include<utility>
using namespace std;

vector<int> stockspan(vector<int>v){
    int n = v.size();
    stack<pair<int,int>> s;
    vector<int>ans;
    
    for(int i=0;i<n;i++){      // time complexity = O(n)
        int days = 1;
        while(!s.empty() && (s.top().first <= v[i])){      // .first and .second to access the
            days += s.top().second;                        // first and second element of
            s.pop();                                       // pair
        }
        s.push({v[i],days});
        ans.push_back(days);
    }
    return ans;
}

int main(){
    
    vector<int> v = {100,80,60,70,60,75,85};
    
    // testing
    vector<int> res = stockspan(v);
    for(auto i:res){
        cout<<i<<" ";
    }
    
    return 0;
}