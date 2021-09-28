#include<iostream>
#include<string>
using namespace std;

// void reverse_string(string s,int i){             //this is also right

//     if(i<s.length()){
    
//          reverse_string(s,i+1);
//         cout<<s[i];
    
//     }

// }

//..............OR..................

void reverse_string(string s){

    if(s.length()==0){
        return;
    }

    string ros=s.substr(1);
    reverse_string(ros);
    cout<<s[0];
}

int main(){

    string s="ayush";

    reverse_string(s);

    return 0;
}