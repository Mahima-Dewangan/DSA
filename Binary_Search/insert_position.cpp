#include<iostream>
#include<vector>
using namespace std;
int searchInsertPos(vector<int> arr , int k)
{
    int n = arr.size();
    int s= 0; int e= n-1;
    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(arr[mid]==k )
        {
                return mid;
        }

        else if(arr[mid]>k)
        {
            e = mid -1;
        }

        else
        {
            s= mid +1 ;
        }
    }

    return s;
}

void main()
{
    vector<int> arr = {1,3,5,6};
    int k;
    cout<<"enter the val you want to search";
    cin>>k;
    cout<<"\nthe search position is "<<searchInsertPos(arr , k);
    
}