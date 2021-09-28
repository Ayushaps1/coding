#include <iostream>
#include<string>
using namespace std;

class bus{

    public :

        int no;p
        string name;
        string atime;   
        string dtime;
        string from;
        string to;

    void detail(){
        cout<<no<<endl;;
        cout<<name<<endl;
        cout<<atime<<endl;
        cout<<dtime<<endl;
        cout<<from<<endl;
        cout<<to<<endl;
    }
}b1,b2,b3,b4;

void install(){
    cout<<"\n\n";
    cout<<"Bus No. :- "<<endl;
    use();
    cout<<"Driver's Name :- "<<endl; 
    cout<<"Arrival Time :- "<<endl;
    cout<<"Departure Time :-"<<endl;
    cout<<"From :- "<<endl;
    cout<<"To :- "<<endl;
}
void Reservation_details(){};
void Sheets_available(){};
void Bus_details(){};

int main() {
  int n;
  
  cout<<"                   |*| * * * * * * * * * * * * *|*|"<<endl;
  cout<<"                   |*|                          |*|"<<endl;
  cout<<"                   |*|   1-Install              |*|"<<endl;
  cout<<"                   |*|   2-Reservation details  |*|"<<endl;
  cout<<"                   |*|   3-Sheets available     |*|"<<endl;
  cout<<"                   |*|   4-Bus details          |*|"<<endl;
  cout<<"                   |*|   5-Exit                 |*|"<<endl;
  cout<<"                   |*|                          |*|"<<endl;
  cout<<"                   |*| * * * * * * * * * * * * *|*|"<<endl;
  
  cout<<"\n\n";
  cout<<"Enter Your Choice :- ";              
  cin>>n;
  switch(n){
  
  case(1):
  		install();
        break;
  case(2):
  		Reservation_details();
        break;
  case(3):
  		Sheets_available();
        break;
  case(4):
  		Bus_details();
        break;
  default :
  			break;
 }
  return 0;
}