#include<bits/stdc++.h>
using namespace std;


// BEST SOLUTION
// TC = O(n)
// SC = O(1) //as we have used ans array to just store and display the output , not for solving the question
void remove(string s)
{
    string ans="";
    int count =0;

    for(int i=0;i<s.length();i++)
    {
    if(s[i]==')')
    {
        count--;
    }
    if(count!=0)
    {
        ans.push_back(s[i]);
    }
    if(s[i]=='(')
    {
        count++;
    }
}

//display the result
for(int i =0;i<ans.length();i++)
{
    cout<<ans[i];
}

}


int main()
{
    string s = "(()())(())";
    remove(s);
    return 0;
}