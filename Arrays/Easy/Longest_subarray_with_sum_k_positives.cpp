#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE
// TC = O(n^2)
// SC = o(1)
// int longest_subarray(vector<int> arr , int k)
// {
//     int len =0;
//     for(int i=0;i<arr.size();i++)-------------------------------O(n)
//     {
//                   int s=0;
//         for(int j=i;j<arr.size();j++)-------------------------------------O(n)
//         {
//             s+=arr[j];
//             if(s == k)
//             len = max(len , j-i+1);
//         }
//     }

//     return len;

// }


// OPTIMAL SOLUTION
// TC =O()
// SC = 0()
int longest_subarray(vector<int>arr, int k)
{
    int l=0;int r=0;
    int sum=arr[0];int maxlen=0;
    int n= arr.size();
    while(r<n)
    {
        while(left<=right && sum>k)
        {
            sum-=arr[l];
            l++;
        } 
        if(sum==k)
        {
            maxlen = max(maxlen , r-l+1);
        }

        r++;
        if(r<n)
        {
            sum+=arr[r];
        }
    }
    return maxlen;
}
int main()
{
    int k;
    cout<<"\nenter the sum you want to find";
    cin>>k;
    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};
    cout<<"\nthe length of the longest subarray with sum "<<k<<" is "<<longest_subarray(arr , k);
    return 0;
}