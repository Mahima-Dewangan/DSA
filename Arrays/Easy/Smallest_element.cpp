#include<bits/stdc++.h>
using namespace std;
// TC = O(n)
int smallest_element(vector<int>arr)
{

    int smallest = arr[0];
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]<smallest)
        {
            smallest = arr[i];
        }
    }

    return smallest ;

}

int main()
{
    vector<int> arr = {100,4,8,56,90};
    cout<<"\nthe smallest element in the array is : "<<smallest_element(arr);
    return 0;

}