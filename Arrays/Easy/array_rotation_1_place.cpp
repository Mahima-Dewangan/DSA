#include<bits/stdc++.h>
using namespace std;
vector<int> array_rotation(vector<int> &arr)
{
    int n= arr.size();
    int temp = arr[0];
    for(int i=1;i<n;i++)
    {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    return arr;
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    cout<<"\n the array after rotation by 1 place is ";
    vector<int> nums = array_rotation(arr);
    for(int i =0;i<arr.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}