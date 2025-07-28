#include<iostream>
#include<vector>
using namespace std;
int binary_search(vector<int> arr , int k)
{
    int n = arr.size();
    int start = 0;
    int end = n-1;

    while(start <= end)
    {
        int mid = start + (end - start) / 2;

        if(arr[mid]== k)
        {
            return mid;
        }

        else if(arr[mid]< k)
        {
           start = mid + 1 ;
        }

        else
        {
           end = mid -1;
        }
    }

    return -1;
}

int main()
{
    int k;
    cout<<"enter the value u want to search";
    cin>>k;

    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    cout<<"give the position where it is found"<<binary_search(arr,k);
    return 0;
}