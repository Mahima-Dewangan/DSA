#include<bits/stdc++.h>
using namespace std;
bool is_balanced(string s)
{
    int length = s.length();
    stack<char> st;
    for(int i=0;i<length;i++)
    {
        char ch = s[i];
        if(ch=='{' || ch=='[' || ch=='(')
        {
            st.push(ch);
        }
        // this will execute when you encounter the closing bracket
        else
        {
            if(st.empty())
            {
                return false;
            }


            char c = st.top();
            if((ch == '}' && c=='{') ||
                (ch==']' && c=='[')  ||
                (ch==')' && c=='('))

            {
                st.pop();
            }

            else
            {
                return false;
            }
        }
    }
        return true;
}

int main()
{
    string s = "(({[]}))";
    cout<<"\n is the paranthesis balanced ? "<<is_balanced(s);
    return 0;
}
