#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){

    string s="absbbbbahsab";
    int st[26]={0};
    for(int i=0;i<s.size();i++){
        st[s[i]-'a']++;
    }
    // this is also right 
    // int mx=0;
    // int id=0;
    // for(int i=0;i<26;i++){
    //     if(st[i]>mx){
    //         mx=st[i];
    //         id=i;
    //     }
    // }
    // cout<<max<<" "<<char(id+'a')<<endl;

    // but i will prefer using this

    int mx=0;
    char ans='a';

    for(int i=0;i<26;i++){

        if(st[i]>mx){
            mx=st[i];
            ans=i+'a';
        }

    }

    cout<<mx<<" "<<ans<<endl;
return 0;
}