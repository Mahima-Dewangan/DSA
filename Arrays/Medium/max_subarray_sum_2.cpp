#include<bits/stdc++.h>
using namespace std;
void max_subarray_sum(vector<int> arr)
{
    int sum =0; 
    int maxi = INT_MIN;
    int start = 0;
    int ansstart =-1;
    int ansend = -1;
    for(int i=0;i<arr.size();i++)
    {
        if(sum == 0)
        start =i;

        sum+=arr[i];

        if(sum > maxi)
        {
            maxi = sum;
            ansstart = start;
            ansend = i;
        }
        if(sum < 0)
        {
            sum =0;
        }
        
    }


    // printing the subarray
    for(int i=ansstart ; i<=ansend ; i++)
    {
        cout<<arr[i]<<" ";
    }
}



int main()
{
    vector<int>arr = {-4,-2,1 , 2,3 ,4 ,-9,0};
    cout<<"\n the subarray of the maximum sum is ";
    max_subarray_sum(arr);
    return 0;
}