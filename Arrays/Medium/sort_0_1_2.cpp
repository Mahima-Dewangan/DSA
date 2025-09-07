#include<bits/stdc++.h>
using namespace std;

// Better solution
// TC = O(2n)
// SC = O(1)
// vector<int>sort_0_1_2(vector<int> arr)
// {
//     int n = arr.size();
//     int cnt0=0; int cnt1=0; int cnt2 =0;

//     for(int i = 0;i<n;i++)  ---------------------O(n)
//     {
//         if(arr[i]==0)
//         {
//             cnt0++;
//         }

//         else if(arr[i]==1)
//         {
//             cnt1++;
//         }
//         else
//         {
//             cnt2++;
//         }
//     }


//    ----- for(int i = 0 ;i<cnt0;i++)
//     {
//         arr[i]=0;
//     }

//     for(int i=cnt0;i<cnt0+cnt1;i++)
//     {
//         arr[i]=1;
//     }
//     for(int i = cnt0+cnt1 ; i < n ;i++)
//     {
//         arr[i]=2;
//     } ------       0(n)

//     return arr;
// }



// OPTIMAL SOLUTION   -----Dutch National Flag Algorithm
// Intuition of the algorithm : [0 ....low-1] -> 0
//                              [low .....mid-1]->1
//                              [high+1.....n-1]->2
// [mid....high] : 0,1,2 will be unsorted
// TC = O(n)
// SC = O(1)
vector<int> sort_0_1_2(vector<int>arr)
{
    int n=arr.size();
    int low =0;
    int mid =0;
    int high = n-1;
    while(mid<=high)
    {
        if(arr[mid]==0)    //---------------if 0 is at the mid , then everything before mid is sorted 
        {
            swap(arr[low] , arr[mid]);
            low++;
            mid++;

        }

        else if(arr[mid]==1)
        {
            mid++;
        }

        else
        {
            swap(arr[mid] , arr[high]); 
            high--;
        }
    }

    return arr;
}
int main()
{
    vector<int> arr = {0,1,2,0,0,2,1,1,2,0};
    cout<<"\n the array after sorting the array is ";
    vector<int> nums = sort_0_1_2(arr);
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}