#include<iostream>
#include<vector>
using namespace std;


// intuition : step 1: find where your mid element lies - first half of the sorted array or second half of the sorted array
//              step 2 : if present in the first half of the sorted array then set e= mid -1;
//               step 3 : if present in the second half of the sorted arrat then set s= mid+1;
int search_rotated_sorted(vector<int> arr , int k )
{
    int n = arr.size();
    int s=0; int e=n-1;
    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(arr[mid]==k)
        {
            return mid;
        }

       /// when the mid is present in the left sorted array
        if(arr[s]<=arr[mid])
        {
            // if the element is present in the left sorted array
            if(arr[s]<=k && k<=arr[mid])
            {
                e=mid-1;
            }

            else
            {
                s= mid+1;
            }
        }

        else
        {
            if(arr[mid]<=k && k<=arr[e])
            {
                s=mid+1;
            }
            else
            {
                e= mid-1;
            }
        }
    }

    return -1;
}

int main()
{
    int k;
    cout<<"nter the target element";
    cin>>k;
    vector<int> arr= {4,5,6,7,0,1,2};
    cout<<"\nthe element is at the position"<<search_rotated_sorted(arr, k);
    return 0;
}
