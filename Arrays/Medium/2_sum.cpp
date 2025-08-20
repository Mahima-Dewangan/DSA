#include<bits/stdc++.h>
using namespace std;
// variety 1 return true / false

// BRUTE FORCE 
// TC = O(n^2)
// SC = O(n)---just the array which is given , no extra space 

// bool two_sum(vector<int>arr , int target)
// {
//     int n = arr.size();
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[i] + arr[j] == target)
//             {
//                 return true;
//             }
//         }
//     }

//     return false;

// }



// BETTER  SOLUTION
// TC = O(n logn) OR O(n) -----as map takes logn OR 1 
// SC = O(n)

// bool two_sum(vector<int>arr , int target)
// {
//     map<int , int>mpp;
//     int n= arr.size();
    
//     for(int i=0;i<n;i++)
//     {
//          int a = arr[i];
//         int more = target - a;
//         if(mpp.find(more)!=mpp.end())   //------------------------------find()   takes O(n) time complexity in case of map
//         {
//             return true;
//         }

//         mpp[a]=i;
//     }

//     return false;
// }


// OPTIMAL SOLUTION (2 pointer approach)
// TC = O(n) + O(n log n)
// SC = O(1)

bool two_sum(vector<int>arr , int target)
{
    sort(arr.begin(), arr.end());    //O(n log n)
    int n= arr.size();
    int left = 0;
    int right = n-1;

    while(left < right)  //O(n)
    {
        int sum = arr[left] + arr[right];
        if(sum == target)
        {
            return true;
        }
        else if(sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return false;
}

int main()
{
    vector<int> arr = {2,6,5,8,11};
    int target;
    cout<<"\nenter the target that you want to find the sum for ";
    cin>>target;
    cout<<" does the two sum  exists ? "<<two_sum(arr , target);
    return 0;
}