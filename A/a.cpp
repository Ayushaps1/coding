#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    long long n,m;
	    cin>>n>>m;
	    long long a[n][m];
	    for(long long i=0;i<n;i++){
	        for(long long j=0;j<m;j++){
	            cin>>a[i][j];
	        }
	    }
	    long long query;
	    cin>>query;
	    
	    while(query--){
	        long long a,b,x,y;
	        cin>>a>>b>>x>>y;
	        a--;
	        b--;
	        x--;
	        y--;
	        for(long long i=a;i<=x;i++){
	            long long sum=0;
	            for(long long j=b;j<=y;j++){
	                sum+=a[i][j];
	            }
	            cout<<sum<<endl;
	        }
	    }
	    
	}
	return 0;
}
