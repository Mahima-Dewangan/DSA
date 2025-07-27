#include<iostream>
#include<vector>
using namespace std;
int find_first_occ(vector<int>arr , int k) 
{
    int n = arr.size();
    int s=0; int e= n-1; int ans =-1;
    while(s<=e)
    {
        int mid = s + (e-s)/2;

        if(arr[mid]==k)
        {
            ans = mid;
            e= mid-1;
        }

        else if(arr[mid]>k)
        {
            e= mid-1;
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
    vector<int> arr = {5,7,7,8,8,10};
    
    int k;                          
    cin>>k;

    cout<<"\nthe first occurrence is at the position:"<<find_first_occ(arr , k);


    return 0;
}