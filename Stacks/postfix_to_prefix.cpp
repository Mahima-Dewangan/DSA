#include<iostream>
#include<stack>
using namespace std;
class Stack{
   public:
   stack<string> st;
   string postToPrefix(string s)
   {
    int n= s.length();
    int i=0;
    while(i<n)
    {
        char ch = s[i];
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        {
            st.push(string(1 , ch));
        }

        else
        {
            string top1 = st.top(); st.pop();
            string top2 = st.top(); st.pop();
            string conc = ch + top2 + top1;
            st.push(conc);
        }

        i++;
    }

    return st.top();
   }

};

int main()
{
    string s;
    cout<<"\nenter the postfix string";
    cin>>s;
    Stack obj;
    string result = obj.postToPrefix(s);
    cout<<"\n the result is"<<result;
    

    return 0;
}