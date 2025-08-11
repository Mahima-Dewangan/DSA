#include<bits/stdc++.h>
using namespace std;

// brute force technique
// TC = O(n)
// int kth_missing(vector<int>arr , int k)
// {
//     for(int i=0;i<arr.size();i++)
//     {
//         if(arr[i]<=k)
//         {
//             k++;
//         }
//         else
//         {
//             break;
//         }
//     }

//     return k;
// }


// optimal solution
// TC = O(log n)
int kth_missing(vector<int>arr, int k)
{
    int low=0;
    int high=arr.size()-1;
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        int missing = arr[mid] - (mid +1);

        if(missing < k)
        {
            low=mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

    return low + k;

}


// why returning low + k ? 
// the idea behind returning low + k is :
// for the last step : missing = arr[high] - (high + 1) ----- eq 1
// for finding   more =  k - missing ----------------------- eq 2
// for finding the missing element = arr[high] + more ----------------eq 3
// substitute the value from eq 1 and eq 2 in eq 3 
//  missing element  =  arr[ high] +  k - (arr[high] - (high +1)
//                    = arr[high] + k - arr[high] + high +1;
//                    = k + high + 1 
// also by the last low = high +1
// so can return low + k  or k + high +1

int main()
{
    vector<int> arr = {2,3,4,7,11};
    int k;
    cout<<"\n enter the kth missing element that u need to find";
    cin>>k;
    cout<<"\nthe "<<k<<" th misssing element is "<<kth_missing(arr , k);
    return 0;
}