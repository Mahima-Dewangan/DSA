#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE : TC = O(n^2)
int count_subarray(vector<int>arr , int k)
{
    map<int ,int>hash;
    hash[0]=1;
    int sum =0;
    int cnt =0;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
        int presum= sum-k;
        cnt+=hash[presum];
        hash[sum]+=1;
    }

    return cnt;
}

int main()
{
    vector<int>arr ={1,2,3,0,3};
    int k;
    cout<<"\nenter the sum";
    cin>>k;
    cout<<"the no of subarray with sum "<<k<<" is "<<count_subarray(arr , k);
    return 0;
}