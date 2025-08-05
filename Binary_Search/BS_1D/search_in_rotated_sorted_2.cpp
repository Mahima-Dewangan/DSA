#include<bits/stdc++.h>
using namespace std;
bool search(vector<int>arr, int k )
{
    int s=0;
    int n= arr.size();
    int e=n-1;
    while(s<=e)
    {
        int mid = s + (e-s)/2 ;
        if(arr[mid]==k)
        {
            return true;
        }
        if(arr[s]==arr[mid] && arr[mid]==arr[e])
        {
            s++;
            e--;
            continue;
        }
        if(arr[s]<=arr[mid])
        {
            if(arr[s]<=k && k<=arr[mid])
            {
                e= mid-1;
            }
            else
            {
                s= mid +1;
            }
        }
        else
        {
            if(k<=arr[mid] && k<=arr[e])
            {
                s=mid +1;
            }
            else
            {
                e = mid -1;
            }
            
        }

      
    }

      return false;
}

int main()
{
    int k;
    vector<int> arr ={3, 3, 3, 1, 2, 3};
    cout<<"\nnter the element you want to find";
    cin>>k;
    cout<<"\nthe ans is"<<search(arr , k);
    return 0;

}