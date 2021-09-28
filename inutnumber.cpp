#include<iostream>
using namespace std;
define n 100

  class stack
   {
      int arr[n];
      int top;
      public:
      stack()
      {
         top=0;
      }
      void push(int x)
      {
         if(top==n)
         {
            cout<<"stack overflow"<<endl;
            return;
         }
         arr[top]=x;
         top++;
      }

      void pop()
      {
         if(top==0)
         {
            cout<<"there is no element is stack"<<endl;
            return;
         }
         top--;
      }

      int top()
      {
         return top;
      }

      bool empty()
      {
         if(top==0)
         {
            return true; 
         }
         return false;
      }
   };

   int main()
   {
      stack st1;
      st1.push(1);
      cout<<st1.top()<<endl;
      st1.pop();
      cout<<st1.top()<<endl;
      cout<<st1.empty();
      
      return 0;
   }
}