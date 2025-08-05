#include<iostream>
#include<vector>
using namespace std;
int array_rotated(vector<int> arr)
{
    int n = arr.size();
    int s=0;
    int e= n-1;
    int ans = INT16_MAX;
    int index = -1;
    while(s<=e)
    {
        int mid= s + (e-s)/2;

        if(arr[s]<=arr[e])
        {
            if(arr[s]<ans)
            {
                index = s;
                ans = arr[s];

            }

            break;
        }


        if(arr[s]<=arr[mid])
        {
            if(arr[s]<ans)
            {
                index = s;
                ans = arr[s];

            }
            s= mid +1;
        }

        else
        {
            e= mid-1;
            if(arr[mid]< ans)
            {
                index = mid;
                ans= arr[mid];

            }
        }
    }

    return index;

}

int main()
{
    vector<int> arr= {5, 1, 2, 3, 4};
    cout<<"\nthe number of times the array is rotated is"<<array_rotated(arr);
    return 0;
}
    

    