#include<iostream>
#include<stack>
using namespace std;
class Stack
{
    public:
    stack <string> st;

   string postfixToInfix(string s)
    {
          int i=0 ; int n=s.length();
          while(i<n)
          {
            char ch = s[i];
            if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9'))
            {
                st.push(string(1 , ch));
            }

            else
            {
                string t1 = st.top(); st.pop();
                string t2 = st.top() ; st.pop();
                string concat = '(' + t2 + ch + t1 + ')';
                st.push(concat);
            }

            i++;


          }


          return st.top();

    }
};

int main()
{
    string s ;
    cout<<"\nenter the postfix string";
    cin>>s;
    Stack obj;

  string result = obj.postfixToInfix(s);
  cout<<"\nthe infix expression is:"<<result<<endl;
  return 0;


}