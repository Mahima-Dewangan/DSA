#include<bits/stdc++.h>
using namespace std;
int max_consecutives_one(vector<int> arr , int k)
{
    int l=0;
    int r=0;
    int count=0;
    int maxlen=0;
    int n=arr.size();
    while(r<n)
    {
        if(arr[r]==0)
        {
            count++;
        }

        if(count>k)
        {
            if(arr[l]==0)
            {
                count--; 
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
    vector<int>arr={1,1,1,0,0,0,1,1,1,1,0};
    int k ;
    cout<<"\nnter the no of consecutive zroes you want";
    cin>>k;
    cout<<"\nthe length of the longest string is"<<max_consecutives_one(arr , k);
    return 0;
}