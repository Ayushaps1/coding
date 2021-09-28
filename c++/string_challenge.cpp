#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    
    string s="hekaldjklsjal";

    // convert to upper case character        //  'A'-'a' = 32  (a>A)

    for(int i=0;i<s.size();i++){
        if(s[i]>='a' && s[i]<='z')
                s[i]-=32;
    }

    cout<<s<<endl;

    // convert to lower case

    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z')
                s[i]+=32;
    }

    cout<<s<<endl;

    //convert to uppercase using transform function

    transform(s.begin(),s.end(),s.begin(),::toupper);
    
    cout<<s<<endl;

    // convert to lowercase  using transform function

    transform(s.begin(),s.end(),s.begin(),::tolower);

    cout<<s<<endl;

    return 0;
}