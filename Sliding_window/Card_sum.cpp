#include<iostream>
#include<vector>
using namespace std;
int cards(vector<int> arr , int k)
{
    int n = arr.size();
    int lsum = 0; int rsum =0; int l =0 ; int r = n-1;
    for(int i=0;i<k;i++)
    {
        lsum+=arr[i];
    }
    int maxsum= lsum;
    for(int i=k-1;i>=0;i--)
    {
        lsum = lsum - arr[i];
        rsum = rsum + arr[r];
        r--;
        maxsum = max(maxsum , lsum + rsum);
    }

    return maxsum;

}

int main()
{
    int k;
    cout<<"nter the max cards I can take";
    cin>>k;
    vector<int> arr={1,2,3,4,5,6,1};
    cout<<"\nthe maximum sum is"<<cards(arr ,k);
    return 0;
}