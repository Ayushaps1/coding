#include <iostream>
using namespace std;

int main() {
  
  int n;
  cin>>n;
  cin.ignore();
  char a[n+1];
  cin.get(a,n);
  cin.ignore();
  
  int i=0;
  int mx=0;
  int current=0;
  
  while(1){
      if(a[i]==' ' || a[i]=='\0'){
          mx=max(mx,current);        
          current=0;
      }
      else{
          current++;
      }
      if(a[i]=='\0'){
          break;
      }
      i++;

  }
  cout<<"maximum word length in the given sentence is = "<<mx; 
  return 0;
}
