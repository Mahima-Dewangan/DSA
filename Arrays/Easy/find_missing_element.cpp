#include<bits/stdc++.h>
using namespace std;
// BETTER SOLUTION
// TC = O(n+n)
// SC = o(n)
// int missing_ele(vector<int>arr)
// {
//     int n = arr.size();
//     vector<int>hash(n+1);

//     for(int i=0;i<n;i++) -----------------------O(n)
//     {
//         hash[arr[i]]=1;
//     }

//     for(int i=1;i<=n;i++)---------------------------o(n)
//     {
//         if(hash[i]==0)
//         {
//          return i;
//         }
//     }
// }

// OPTIMAL SOLUTION ---1 (in this solution we are calculating sum , which for alarge number can exceed the range of the integer)
// TC = O(n)
// SC = O(1)
// int missing_ele(vector<int>arr , int N)
// {
    
//     int sum = (N*(N+1))/2;
//     int s2 = 0;
//     for(int i = 0 ;i<N-1;i++)
//     {
//         s2+=arr[i];
//     }

//     return (sum - s2);
// }

// OPTIMAL SOLUTION ------------2 (XOR will remain within the range of the integer)
// TC = O(n)
// SC = O(1)
int missing_ele(vector<int> arr , int N)
{
    int xor1 =0;
    int xor2=0;
    for(int i=0;i<N-1;i++)
    {

            xor2=xor2^arr[i];
            xor1 = xor1^(i+1);

    }

    xor1=xor1^N;
    return xor2^xor1;
}
int main()
{
    vector<int>arr = {8, 2, 4, 5, 3, 7, 1};
    int n=arr.size();
    cout<<"/nthe missing element in the array is :"<<missing_ele(arr , n+1);
    return 0;
}