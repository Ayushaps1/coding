#include <iostream>
using namespace std;

int main() {
  
  int n;
  cin>>n;
  cin.ignore();
  char a[n+1];
  cin.get(a,n+1);
  cin.ignore();
  int i=0;
  bool t=0;

  while(i<n){
      if(a[i]!=a[n-1-i]){
          t=1;
          break;
      }
      i++;
  }
  if(1){
      cout<<"This is not palindrome";
  }
  else{
      cout<<"This is not palindrome";
  }
  return 0;
}
