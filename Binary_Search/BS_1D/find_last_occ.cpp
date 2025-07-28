#include<iostream>
#include<vector>
using namespace std;

int last_occ(vector<int>arr , int k)
{
    int ans = -1;
    int n = arr.size();
    int s= 0;
    int e= n-1;

    while(s<=e)
    {
        int mid = s+(e-s)/2;

        if(arr[mid]==k)
        {
            ans= mid;
            s=mid+1;

        }

        else if(arr[mid]>k)
        {
            e = mid-1;
        } 
        else
        {
            s= mid +1;
        }
    }
    return ans;

}

int main()
{
    int k;
    vector<int> arr = {5,7,7,8,8,10};
    cout<<"\nenter the element whose last occ you want to find";
    cin>>k;
    cout<<"\nthe last occ is present at the pos"<<last_occ(arr , k);
    return 0;
}
