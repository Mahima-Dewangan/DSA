#include<iostream>
#include<stack>
using namespace std;
class Stack
{
    public:
    stack<string> st;
    string prefixToInfix(string s)
    {
        int n = s.length(); int i= n-1; 
        while(i>=0)
        {
            char ch = s[i];
            if((ch>='A' && ch<='Z') || (ch>='0' && ch<='9') || (ch>='a' && ch<='z'))
            {
                st.push(string(1, ch));
            }

            else
            {
                string top1 = st.top(); st.pop();
                string top2 = st.top(); st.pop();
                string concat = '(' + top1 + ch + top2 + ')';
                st.push(concat);
            }

            i--;
        }

        return st.top();

    }
};


int main()
{
    string s;
    cout<<"\n enter the prefix string";
    cin>>s;
    Stack obj;
    string result = obj.prefixToInfix(s);
    cout<<"\n the infix expression is:"<<result;
    return 0;
}