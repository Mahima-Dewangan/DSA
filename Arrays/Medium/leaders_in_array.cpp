#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE 
// TC = O(n^2)
// SC = O(n)
// void leaders(vector<int>arr)
// {
//     int n = arr.size();
//     vector<int>ans;
//     for(int i =0 ;i<n;i++)
//     {
//         bool leader = true;
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[j]>arr[i])
//             {
//                 leader = false;
//                 break;
//             }
//         }

//         if(leader==true)
//         {
//             ans.push_back(arr[i]);
//         }
//     }

//     for(int i =0;i<ans.size();i++)
//     {
//         cout<<ans[i]<<" ";
//     }
    
// }

// OPTIMAL SOLUTION
// TC = O(n)
// SC = O()

void leaders(vector<int>arr)
{
    int maxi = INT_MIN;
    vector<int>ans; 
    for(int i=arr.size()-1;i>=0;i--)
    {
        if(arr[i]>maxi)
        {
            ans.push_back(arr[i]);
        }

        maxi = max(maxi, arr[i]);
    }

    // printing the ans 
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}

int main()
{
    vector<int>arr = {10 , 22 , 12, 3 , 0 , 6};
    cout<<"\nthe leaders of the array are : ";
    leaders(arr);
    return 0;
}