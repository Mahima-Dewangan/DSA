#include<bits/stdc++.h>
using namespace std;
int second_smallest(vector<int>arr)
{
    int smallest = arr[0] ;
    int second_smallest = -1;

    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]<smallest)
        {
           
            second_smallest = smallest;
             smallest = arr[i];
        }

        else if(arr[i]> smallest && arr[i]<second_smallest)
        {
            second_smallest = arr[i];
        }
    }

    return second_smallest;
}

int main()
{
    vector<int> arr = {100 , 4, 8, 56, 90};
    cout<<"\nthe second largest element in the array is "<<second_smallest(arr);
    return 0;
}