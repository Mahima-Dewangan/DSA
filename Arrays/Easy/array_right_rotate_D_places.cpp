#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE 
// TC = 
// SC = O(d)
vector<int> right_rotate(vector<int> &arr , int d)
{
     int n= arr.size();
     d = d%n;
    vector<int> temp(d);
    
    // step 1 : push the element to temp 
    int j = 0;
    for(int i=n-1;i>=n-d;i--)
    {
        temp[j++] = arr[i];
    }

    // step 2 : shift the element to right 
    for(int i = 0;i<n-d;i++ )
    {
        arr[i+d] = arr[i];
    }

    // step 3 : put the element back to the aray
    for(int i= 0;i<d;i++)
    {
        arr[i]=temp[i];
    }

    return arr;
}


int main()
{
    vector<int> arr= {1,2,3,4,5};
    int d;
    cout<<"\nenter the dth place : ";
    cin>>d;
    vector<int> nums = right_rotate(arr , d);
    cout<<"\narray after right rotation by dth place is ";
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }

    return 0;
    
}