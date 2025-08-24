#include<bits/stdc++.h>
using namespace std;
// Brute force technique
// TC = O(n)
// SC = O(n)
void rearrange(vector<int>arr)
{
    int n = arr.size();
    vector<int>pos;
    vector<int>neg;
    for(int i=0;i<n;i++) //------------------------O(n)
    {
        if(arr[i]<0)
        {
            neg.push_back(arr[i]);
        }
        else
        {
            pos.push_back(arr[i]);
        }
    }

    for(int i=0;i<n/2;i++)  //---------------------O(n/2)
    {
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];
    }

//   printing the array
   for(int i =0;i<n;i++ )
   {
       cout<<arr[i]<<" ";
   }
}

int main()
{
    vector<int>arr={2,3,-8,-7,5,-1};
    cout<<"\nafter rearranging the arary will be ";
    rearrange(arr);
}