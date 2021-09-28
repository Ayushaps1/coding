#include<iostream>
using namespace std;

int setbit(int n,int pos){    //set bit means setting 1 at pos 
    return(n|(1<<pos));
}

int main(){
    cout<<setbit(5,1);
    return 0;
}