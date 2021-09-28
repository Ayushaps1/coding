//using euclid theorem to find GCD (greatest common devisior)
                            // [gcd=(hcf of n and m the choose common factor and multiply them)]
#include<iostream>
using namespace std;

void gcd(int n,int m){

    while(m!=0){                        // or      
        int t = n%m;                    // while(m!=0){
        n=m;                            //     int t=n-m;  <---if(n>m) else---> t=m-n 
        m=t;                            //      n=m; m=t;}                      m=n; n=t;}
    }                                    //     cout<<n;                        cout<<m;

    cout<<n<<endl;

}

int main(){

    int n,m;
    cin>>n>>m;

    gcd(n,m);

    return 0;
}