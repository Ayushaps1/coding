#include <iostream>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    string a[k];
	    bool res = true;
	    
	    for(int i = 0;i<k;i++){
	        cin>>a[i];
	        string s = a[i];
	        cout<<s<<endl;
	        int ans = 0;
	        if(s[0] >= 'a' && s[i] <='m'){
	            ans = 1;
	        }
	        else{
	            ans =2;
	        }
	        cout<<"ans = "<<ans<<endl;
	        for(int j = 0; j<s.size(); j++){
	            
	            if(s[i] >='a' && s[i] <= 'm'){
	                if(ans != 1){
	                   cout<<"NO"<<endl;
	                   res = false;
	                   break;
	                }
	            }
	            else if(s[i] >='N' && s[i] <='Z'){
	                if(ans != 2){
	                    cout<<"NO"<<endl;
	                    res = false;
	                    break;
	                }
	            }
	            else{
	                cout<<"NO"<<endl;
	                res = false;
	                break;
	            }
	        }
	        if(res = false){
	            break;
	        }
	    }
	    if(res){
	        cout<<"YES"<<endl;
	    }
	}
	
	return 0;
}
