#include<iostream>
using namespace std;

int main(){
    int n,m,k,x1,y1,x2,y2,h;
    cin>>n>>m>>k;
    /*if(y1==y2 || y1==(y2+1) || y2==(y1+1)){
        h=y1;
    }
    else{
        h=(y1+y2)/2;
    }*/
    int sum=0;
    while(k--){
        cin>>x1>>y1>>x2>>y2;
        int X=x1>x2?(x1-x2):(x2-x1);
        int Y=y1>y2?(y1-y2):(y2-y1);
        if()
        sum+=(X+2*Y);
    }
    cout<<sum<<endl;    
    return 0;
}