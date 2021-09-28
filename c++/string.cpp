#include<iostream>
#include<string>
#include<cstring>      //this header file is here only for strcpy();
#include<algorithm>
using namespace std;

int main(){
    string str="hello";
    string st(10,'a');       ///it will create a string with 10 characters where all characters are 'a'
    
    str.assign("ayush");     //using assign() function
    str="singh";
    cout<<str.length()<<" ";        //using length() function
    cout<<str.size()<<" ";          //using size() function (same as length() function returns size or length)   
    cout<<str.compare(st)<<" ";  // using compare() function to compare str and st if +ive (str>) 0(equal) -ive (str<)    
    cout<<str.capacity()<<" "; // using capacity() function returns capacity allocated (no. of memory blocks allocated)
    
    string sz="897";
    int x=stoi(sz);     //using stoi() function to convert string to int datatype
    cout<<endl<<"x = "<<x;
    cout<<endl<<"x ="<<++x;
    cout<<endl<<"sz ="<<sz;
    
    sz.append("hello");   // using append() function add character at the end of string sz
    cout<<endl<<"sz = "<<sz;
    
    cout<<endl<<sz.at(3)<<" "<<sz[3];    //using at() function same as []
    
    str=to_string(x);           // using to_string() function to cconvert int data to string 
    cout<<endl<<"str = "<<str;
    
    str+=sz;                   //  using += same as append()
    cout<<endl<<"str = "<<str;
    
    cout<<endl<<str.empty();   //using empty() function returns booliean value 0 if not empty ,1 if empty
    
    str.clear();             // using clear() to clear all data inside str.
    cout<<endl<<str.empty();
    
    str="how is going";
    cout<<endl<<str.size();   
    cout<<endl<<str.capacity();
    str.resize(6);              //uisng resize() to resize the str
    cout<<endl<<str.size();
    cout<<endl<<str.capacity();
    
    str.assign("how is going");   // using assign() same as =
    
    str.erase(4,2);             // using erase() to erase a substring of length 2 starting from index 4
    cout<<endl<<"str = "<<str;
    
    cout<<endl<<str.find("going");  //using find() to find the substring returns the starting index of substring

    cout<<endl<<"substring = "<<str.substr(5,5);    //using substring function to copy of substring  of size 5
                                                    // and starting index also 5
    cout<<endl<<str.find("going");         
    cout<<endl<<"str = "<<str;

    str="how is going";
    sort(str.begin(),str.end());      //ascending order  (sorting)
    cout<<endl<<"str = "<<str;

    sort(str.begin(),str.end(),greater<int>());  //descending order
    cout<<endl<<"str = "<<str;

    str="how is going";
    char a[str.length()+1];               //
    strcpy(a,str.c_str());
    cout<<endl<<"c-string a = "<<a;
    
    str="895";              // str="hello" this would be wrong only int inside double quotes
    cout<<endl<<"str = "<<str;
    int b=stoi(str);
    cout<<endl<<"b = "<<x;
    return 0;
}