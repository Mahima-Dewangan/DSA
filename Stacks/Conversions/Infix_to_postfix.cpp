#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Stack
{
    public:
    stack<char>st;

    public:
    int priority(char ch)
    {
        switch(ch)
        {
            case '+':
            case '-':
            return 1;

            case '*':
            case '/':
            return 2;
            
            case '^':
            return 3;

            default:
            return -1;
        }
    }
   string infixtopostfix(string s )
    {
         int i=0; string ans="";
        while(i<s.length())
        {
             char ch = s[i]; 

            //  ddealing with operands
             if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0'&& ch<='9'))
             {
                      ans+=ch;
             }

            //  dealing with opening bracket
             else if(ch == '(')
             {
                st.push(ch);
             }

            //  dealing with closing bracket
             else if(ch==')')
             {
                while(!st.empty() && st.top()!='(')
                {
                    ans+=st.top();
                    st.pop();
                }
                st.pop(); // to pop the ( bracket
            }

            // dealing with operators
            else
            {
                while(!st.empty() && priority(ch) <= priority(st.top()))
                {
                        ans+=st.top();
                        st.pop();
                }

                st.push(ch);

            }

            i++;
        }


        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }

        return ans;
     }

    
};

int main()
{

    string s;
    cout<<"nter infix expression";
    cin>>s;

    Stack obj;
    string result = obj.infixtopostfix(s);
    cout<<"postfix expression:"<<result<<endl;
    return 0;

}