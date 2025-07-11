#include<iostream>
#include<stack>
using namespace std;
class Stack
{
    public:
    stack<string>st;
    string preToPost(string s)
    {
    int n= s.length(); int i=n-1;
    while(i>=0)
    {
        char ch = s[i];
        if((ch>='a' && ch<='z') || (ch>='0' && ch<='9') || (ch>='A' && ch<='Z'))
        {
            st.push(string(1 , ch));
        }
        else
        {
            string top1 =  st.top(); st.pop();
            string top2 =  st.top(); st.pop();
            string conc=   top1 + top2 +ch;
            st.push(conc);
        }

        i--;

    }
    return st.top();
}
};

int main()
{
    string s;
    cout<<"\nenter the  prefix string:";
    cin>>s;
    Stack obj ;
    string result = obj.preToPost(s);
    cout<<"\n the postfix string is:"<<result;
    return 0;
}
