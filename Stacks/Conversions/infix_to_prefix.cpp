#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
class Stack
{
    public:
    stack<int> st;
    string reversed(string s)
    {
         reverse(s.begin(), s.end()); // Step 1: Reverse the entire string

        // Step 2: Swap '(' with ')' and vice versa
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(') {
                s[i] = ')';
            }
            else if (s[i] == ')') {
                s[i] = '(';
            }
        } 

        return s;
    }

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

    

    string infixtoprefix(string &s)
     {
           int i=0; string ans=""; 

              //    reverse the string and change the brackets
             s= reversed(s);
           while(i<s.length())
           {

                char ch = s[i];
               //    dealing with operands
              if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9'))
              {
                ans+=ch;
              }

                //   dealing with the opening bracket
                else if(ch=='(')
                 {
                   st.push(ch);
                 }
                 //   dealing with the closing bracket
                else if(ch==')')
                 {
                    while(!st.empty() || st.top()!='(')
                    {
                        ans+=st.top();
                        st.pop();
                    }

                    st.pop(); //to pop out the opening bracket
                 }

            //   delaling with operators under some controlled conditions

              else
              {
                    if(ch=='^') ///this if block basically tells that no two ^ stays in the stack at the same time
                    {
                         while(!st.empty() && priority(ch)<=priority(st.top()))
                        {
                             ans+=st.top();
                             st.pop();
                        }

                   
                     }

                    else
                    {
                         while(!st.empty() && priority(ch)<priority(st.top()))
                        {
                             ans+=st.top();
                             st.pop();
                         }

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
           reverse(ans.begin() , ans.end());
           return ans;
     }
    
};

int main()

{
    string s;
    cout<<"nter the infix string";
    cin>>s;

    Stack obj;
    string result = obj.infixtoprefix(s);
    cout<<"the prefix expression is"<<result<<endl;
    return 0;
}