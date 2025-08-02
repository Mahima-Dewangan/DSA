#include<bits/stdc++.h>
using namespace std;
int find_min(vector<int> arr)
{
    int n = arr.size();
    int s = 0;
    int e= n-1;
    int ans = INT_MAX;
    while(s<=e)
    {
        int mid = s +(e-s)/2;
        if(arr[s]<=arr[mid])
        {
            ans = min(ans , arr[s]);
            s= mid+1;
        }

        else
        {
             
            ans = min(ans , arr[mid]);
            e=mid-1;
           
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {5,1,2,3,4};
    cout<<"\nthe min element in rotated sorted array is "<<find_min(arr);
    return 0;
}