#include<iostream>
#include<vector>
#include<string>
using namespace std;

int longestsubstring(string s){
    int len = 0;
    int ans = -1;
    vector<int> v(26,-1);

    for(int i=0;i<s.size();i++){
        
        if(v[s[i]-'a'] != -1){
            ans = max(ans,len);
            len = 0;
        }
        else{
            v[s[i]-'a'] = 0;
        }

        len++;
        ans = max(ans,len);
    }
    return ans;
}

int main(){

    string s;
    cin>>s;

    //length of longest substring in a given string
    cout<<"Length of longest substring in a given string is "<<longestsubstring(s)<<endl;

    return 0;
}