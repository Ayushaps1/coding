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
  int si=0,ei=0;
  while(1){
      if(a[i]==' ' || a[i]=='\0'){
          if(current > mx){
              mx=current;
              ei=i-1;
              si=ei-current+1;
          }        
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
  cout<<"maximum word length in the given sentence is = "<<mx<<endl;
  cout<<"starting and ending index of biggest word is = "<<si<<","<<ei<<endl; 
  for(int i=0;i<mx;i++){
      cout<<a[i+si];
  }
  return 0;
}
