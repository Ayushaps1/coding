// Program to find the largest rectangle in histogram 
// in linear time
#include<iostream>
#include<stack>
using namespace std;

int largestRec(int a[],int n){          // time complexity = O(n)
    int ans = 0;
    int i = 0;
    stack<int> s;

    while(i < n){
        
        while(!s.empty() && (a[s.top()] > a[i])){
            int h = a[s.top()];
            s.pop();
            if(s.empty()){
                ans = max(ans,h*i);
            }
            else{
                int len = i-s.top();
                ans = max(ans,h*len);
            }
        }
        s.push(i);
        i++;
    }

    
    while(!s.empty()){
        
        int h = a[s.top()];
        s.pop();
        if(s.empty()){
            ans = max(ans,h*i);
        }
        else{
            int len = i-s.top()-1;
            ans = max(ans,h*len);
        }

    }
    return ans;

}

int main(){

    int a[] = {2,3,4};
    int n = sizeof(a)/sizeof(a[0]);

    // finding largest rectangle in a histogram 
    cout<<largestRec(a,n)<<endl;

    return 0;
}