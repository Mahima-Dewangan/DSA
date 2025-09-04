#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE 
// TC = O(n^2)
// SC = O(1)
// int max_prod(vector<int>arr)
// {
//     int n = arr.size();
//     int maxi = INT_MIN;
//     for(int i =0;i<n;i++)
//     {
//         int prod = 1;
//         for(int j=i;j<n;j++)
//         {
//             prod=prod*arr[j];
//             maxi = max(maxi , prod);
//         }
//     }

//     return maxi;
// }

// OPTIMAL SOLUTION
// TC = O(n)
// SC =O(1)
 int max_prod(vector<int>arr)
 {
    int maxi = INT_MIN;
    int prefix =1;
    int suffix = 1;
    int n = arr.size();
    for(int i =0;i<n;i++)
        {
            if(prefix ==0) prefix =1;
            if(suffix==0) suffix==1;

            prefix = prefix * arr[i];
            suffix = suffix * arr[n-i-1];

            maxi = max(maxi , max(prefix , suffix));

        }

        return maxi;
 }
int main()
{
    vector<int>arr = {2,3,-2,4};
    cout<<"the maximum product of the array is :"<<max_prod(arr);
}