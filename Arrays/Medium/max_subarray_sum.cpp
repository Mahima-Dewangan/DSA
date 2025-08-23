#include<bits/stdc++.h>
using namespace std;

// Better Solution
// TC = O(n^2)
// SC = O(1)
// int max_subarray_sum(vector<int>arr)
// {
//     int n = arr.size();
//     int maxi = 0;
//     for(int i =0 ;i<n;i++)
//     {
//         int sum = 0;
//         for(int j=i;j<n;j++)
//         {
//             sum+=arr[j];
//             maxi = max(maxi , sum);
//         }
//      }

//      return maxi;
// }

// OPTIMAL SOLUTION --- KADEN'S ALGORITHM
// TC = O(n)
// SC = O(1)
int max_subarray_sum(vector<int>arr)
{
    int sum = 0 ; int maxi = INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];

        maxi = max(sum , maxi);
        
        if(sum < 0)
        {
            sum=0;

        }
    }


    // in order to include the empty subarray 
    if(maxi < 0)
    {
        maxi = 0;
    }

    return maxi;
}
int main()
{
    vector<int>arr = {-2 , -3 , -2 , -1};
    cout<<"\n the maximum subarray sum of the array is "<<max_subarray_sum(arr);
    return 0;
}