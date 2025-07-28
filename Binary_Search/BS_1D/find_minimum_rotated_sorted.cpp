#include<iostream>
#include<vector>
using namespace std;
int find_minimum(vector<int>arr)
{
    int n = arr.size();
    int s=0;int e =n-1;
    int ans = INT16_MAX;
    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(arr[s]<=arr[mid])
        {
            ans = min(ans , arr[s]);
            s = mid +1;
        }
        else
        {
            e= mid-1;
            ans = min(ans ,arr[mid]);
        }
    }

    return ans;
}
int main()
{
    vector<int> arr ={3,4,5,1,2};
    cout<<"\nthe minimum element is"<<find_minimum(arr);
}