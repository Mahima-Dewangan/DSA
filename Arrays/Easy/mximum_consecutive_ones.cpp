#include<bits/stdc++.h>
using namespace std;
// Optimal Solution
// TC = O(n)
// SC= o(1)
int max_ones(vector<int>arr)
{
    int n = arr.size();
    int count = 0;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            count++;
            maxi = max(maxi , count);
        }
        else
        {
            count=0;
        }
    }

    return  maxi;

}

int main()
{
    vector<int>arr = {1,1,0,1,1,1,1};
    cout<<"\nmaximum consecutive ones in a given array is "<<max_ones(arr);

    return 0;

}
