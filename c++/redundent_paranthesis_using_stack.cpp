#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool redundent_paranthesis(string st){
    int n = sizeof(st)/sizeof(st[0]);
    stack<char> s;
    bool ans = false;

    for(int i=0;i<n;i++){
        if(st[i] == '+' || st[i] == '-' || st[i] == '*' || st[i] == '/'){
            s.push(st[i]);
        }
        else if(st[i] == '('){
            s.push(st[i]);
        }
        else if(st[i] == ')'){
            if(s.empty() || (s.top() == '(')){
                ans = true;
                return ans;
            }
            //you can also replace this =  !s.empty() && (s.top() != '(')
            // with  st[i] == '+' || st[i] == '-' || st[i] == '*' || st[i] == '/'
            while(!s.empty() && (s.top() != '(')){
                s.pop();
            }
            s.pop();
        }
    }
    return ans;
}

int main(){

 string s;
 cin>>s;

 //checking if there's any redundent parenthesis is available
 cout<<redundent_paranthesis(s)<<endl;   

    return 0;
}