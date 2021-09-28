#include<iostream>
using namespace std;
#define n 100

class stack
    {
        int a[n];
        int Top;

        public:
        stack()
        {
            Top=-1;
        }
        void push(int x)
        {
            if(Top==n-1)
            {
                cout<<"stack overflow"<<endl;
                return;
            }
            Top++;
            a[Top]=x;
        }

        void pop()
        {
            if(Top==-1)
            {
                cout<<"there is no element in stack"<<endl;
                return;
            }
            Top--;
        }

        int top()
        {
            if(Top==-1)
            {
                cout<<"there is no element in stack"<<endl;
                return -1;
            }
            return a[Top];
        }

        bool empty()
        {
            if(Top==-1)
            {
                return 1;
            }
            return 0;
        }
    };

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.empty()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.empty()<<endl;

    return 0;
}