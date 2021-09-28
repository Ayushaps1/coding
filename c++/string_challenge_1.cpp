#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){

    string s="7847687375893";

    sort(s.begin(),s.end(),greater<int>());   //instead of int we could also used char 
    cout<<s;

    return 0;
}