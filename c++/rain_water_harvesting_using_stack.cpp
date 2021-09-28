// Program to find the area of water stored in rain water harvesting
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int rain_water(vector<int> a){  // Time complexity = O(n)
    int n = a.size();
    int ans = 0;
    stack<int> s;

    for(int i=0;i<n;i++){       
        while(!s.empty() && (a[s.top()] < a[i])){
            int h = a[s.top()];
            s.pop();
            if(s.empty()){
                break;
            }
            int diff = i-s.top()-1;
            ans += (min(a[s.top()],a[i]) - a[h])*diff;  
            // a[s.top()] = left boundary of container
            // a[h] = right boundary of container
            // diff = width of middle part of container
        }
        s.push(i);
    }
    return ans;
}

int main(){

    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    // finding area of water stored
    cout<<"Rain water storage area = "<<rain_water(a)<<endl;

    return 0;
}