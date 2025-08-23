#include<bits/stdc++.h>
using namespace std;
// TC = O(n)
int stocks(vector<int>arr)
{
    int profit =0;
    int mini = arr[0];
    for(int i =1;i<arr.size();i++)
    {
        int cost = arr[i] - mini;
        profit = max(profit ,cost);
        mini = min(arr[i], mini);
    }

    return profit;
}

int main()
{
    vector<int>arr ={7,1,5,3,6,4};
    cout<<"\nthe profit after buying and selling the stock is "<<stocks(arr);
    return 0;
}