#include<iostream>
#include<vector>
using namespace std;
int first_occ(vector<int>arr , int k) 
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

int count_duplicates(vector<int> arr , int k)
{
    int first = first_occ(arr,k);
    int last = last_occ(arr , k);

    if(first == -1 || last == -1)
    {
        return 0;
    }

    else

    {
        return last - first+1;
    }
}

int main()
{
    int k;
    vector<int> arr = {5,7,7,8,8,10};
    cout<<"\nenter the element whose last occ you want to find";
    cin>>k;
    cout<<"\nthe no of  occ is"<<count_duplicates(arr , k);
    return 0;
}