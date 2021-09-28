#include<iostream>
#include<climits>
using namespace std;

int isfeasible(int a[],int n,int limit){
	int sum = 0;
	int painters = 1;
	for(int i=0;i<n;i++){
		if(sum+a[i] > limit){
			painters++;
			sum = a[i];
		}
		else{
			sum += a[i];
		}
	}
	return painters;
}

int minimumallocation(int a[],int n,int m){
	int start = INT_MIN;
	int totalL = 0;
	for(int i=0;i<n;i++){
		start = max(start,a[i]);
		totalL += a[i];
	}
	int end = totalL;
	int ans = INT_MAX;
	while(start<end){
		int mid = (start+end)/2;
		int painters = isfeasible(a,n,mid);
		if(painters <= m){
			ans = min(ans,mid);
			end = mid;
		}
		else{
			start = mid+1;
		}
	}
	return ans;
}

int main(){

	int a[] = {10,20,30,40};
	int n = 4;
	int m = 2;

	// testing 
	cout<<"maximum time = "<<minimumallocation(a,n,m);

	return 0;
}