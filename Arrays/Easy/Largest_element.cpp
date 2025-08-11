#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE
// SORT THE ARRAY ----- O(n log n)
//  return the element at arr[n-1 ].


// OPTIMAL SOLUTION
// TC = O(n)

int largest_ele(vector<int> arr)
{
    int largest = arr[0];
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]>largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

int main()
{
    vector<int>arr = {10,93,20,60 ,40};
    cout<<"\nthe largest element in the array is "<<largest_ele(arr);
    return 0;
}
