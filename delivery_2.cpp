#include<iostream>
using namespace std;

void dislay(char s[]){
    cout<<"Entered char array is "<<s<<endl;
}

void dislay(string s){
    cout<<"Entered string is "<<s<<endl;
}

int main(){
    char str[100];
    string str1;
    
    cout<<"Enter a string = ";
    getline(cin,str1);
    cout<<"\nEnter another string =";
    cin.get(str,100);
    dislay(str);
    dislay(str1);
    return 0;
}