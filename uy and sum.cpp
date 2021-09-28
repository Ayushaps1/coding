#include<iostream>
using namespace std;

int main(){
    int n,m,x1,x2,y1,y2;
    cin>>n>>m>>x1>>x2>>y1>>y2;
    if(y1==y2 || y1==(y2+1) || y2==(y1+1)){
        h=y1;
    }
    else{
        h=(y1+y2)/2;
    }
    cout<<h<<endl;
    return 0;
}