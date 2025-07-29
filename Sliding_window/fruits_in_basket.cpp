#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int fruits_in_basket(vector<int>arr)
{
    int n = arr.size();
    int l=0;
    int r=0;
    int maxlen=0;
    unordered_map<int,int>hash;
    while(r<n)
    {
        hash[arr[r]]++;
        if(hash.size()>2)
        {
            hash[arr[l]]--;
            if(hash[arr[l]]==0)
            {
                hash.erase(arr[l]);
            }
            l++;
        }

        maxlen=max(maxlen , r-l+1);
        r++;
    }

    return maxlen;

}

int main()
{
    vector<int> arr = {3, 1, 2, 2, 2, 2};
    cout<<"the max length of the distinct fruit in the basket is"<<fruits_in_basket(arr);
    return 0;
}