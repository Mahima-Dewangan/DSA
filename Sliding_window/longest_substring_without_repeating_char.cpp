#include<bits/stdc++.h>
using namespace std;
int no_repeating_char(string s)
{
    int n= s.size();
    int l=0; int r=0;
    int maxlen=0;
    unordered_map<char , int>hash;
    while(r<n)
    {
        if(hash[s[r]]!=-1 && hash[s[r]]>=l)
        {
                l= hash[s[r]]+1;
        }

    

    hash[s[r]]=r;
    maxlen = max(maxlen , r-l+1);
    r++;
    }
    return maxlen;
}

int main()
{
    string s="geeksforgeeks";
    cout<<"\nthe maximum length of the substring is:"<<no_repeating_char(s);
    return 0;
}