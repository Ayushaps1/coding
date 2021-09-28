#include<iostream>
#include<limits>
using namespace std;

void occurence(int a[],int n,int key,int i,int first,int last){
    

    if(n==0){
        if(first==INT_MAX && last==INT_MIN){
            cout<<-1<<endl;
            return;
        }
        cout<<first<<" "<<last<<endl;
        return;
    }

   
    if(a[i]==key){

        first=min(first,i);
        last=max(last,i);
    
    }

    occurence(a,n-1,key,i+1,first,last);
    
}

//..............OR........................

int firstocc(int a[],int n,int i,int val){
    if(i==n){
        return -1;
    }
    
    if(a[i]==val){
        return i;
    }
    return(firstocc(a,n,i+1,val));
}

int lastocc(int a[],int n,int i,int val){
    if(i==n){
        return -1;
    }
    int restarray=lastocc(a,n,i+1,val);
    if(restarray!=-1){
        return restarray;
    }
    if(a[i]==val){
        return i;
    }
}

int main(){

    int a[]={1,2,3,4,5,2,3,2};
    int first=INT_MAX;                 //
    int last=INT_MIN;                  //...... this for first function
    occurence(a,8,2,0,first,last);     //
    cout<<firstocc(a,8,0,2)<<endl;
    cout<<lastocc(a,8,0,2)<<endl;
    return 0;
}