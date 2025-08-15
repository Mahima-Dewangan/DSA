#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE 
// TC = O(2n)
// SC = O(x)  ----------------(in worst case , when no zero is present in the array : O(n))

// vector<int> move_zeros(vector<int> &arr)
// {
//     int n = arr.size();
//     vector<int>temp;
//     // step 1 : put the non zero values in the temp array-------------------------O(n)
//     for(int i = 0 ;i<n;i++)
//     {
//         if(arr[i]!=0)
//         temp.push_back(arr[i]);
//     }

//     int x = temp.size();

//     // step 2 : put the non zero values back to the original array-------------------------O(x)
//     for(int i=0;i<x;i++)
//     {
//         arr[i]=temp[i];
//     }

//     // step 3 : at the remaining places put zeros;------------------------------O(n-x)
//     for(int i= x;i<n;i++)
//     {
//         arr[i]=0;
//     }

//     return arr;

// }

// OPTIMAL SOLUTION
// TC = 0(n)
vector<int> move_zeros(vector<int> &arr)
{
    int j=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    return arr;
}

int main()
{
    vector<int>arr = {1,2,3,4,0,5,6,0,9};
    vector<int>nums = move_zeros(arr);
    cout<<"\nthe array after moving the array to the end is ";
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }


    return 0;
}