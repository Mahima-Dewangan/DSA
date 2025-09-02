#include<bits/stdc++.h>
using namespace std;
void reverse_words(string s)
{
    reverse(s.begin() , s.end());
    string ans="";
    for(int i=0 ; i<s.length(); i++)
    {
        string word="";
        while(i<s.length() && s[i]!=' ')
        {
            word+=s[i];
            i++;
        }

        reverse(word.begin() ,  word.end());
        if(word.length()>0)
        {
            ans+=" "+word;
        }
    }

    // display the result
    for(int i=1;i<ans.length();i++)
    {
        cout<<ans[i];
    }

}

int main()
{
    string s ="the sky is blue";
    cout<<"\n the result is\n";
    reverse_words(s);
    return 0;
}