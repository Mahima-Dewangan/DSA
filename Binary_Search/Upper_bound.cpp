#include<iostream>
#include<vector>
using namespace std;
 int lower_bound(vector<int> arr , int k)
{
    int n = arr.size();
    int start = 0;
    int ans =-1;
    int end = n-1;
    while(start<=end)
    {
        int mid = start + (end - start)/2;

        if(arr[mid]>=k)
        {
                ans = mid;
                end = mid -1;
        }

        else 
        {
            start= mid +1;
        }
    }
    return ans;

}

int main()
{
    int k;
    cout<<" enter the number whose lower bound u want to find";
    cin>>k;

    vector<int>arr ={1, 2, 8, 10, 10, 12, 19};
    cout<<"\nthe lower bound is"<<lower_bound(arr,k);
        return 0;
}