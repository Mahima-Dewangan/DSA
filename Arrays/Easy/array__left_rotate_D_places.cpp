#include<bits/stdc++.h>
using namespace std;
// Brute Force ------------------ TC = O(n+d)
// ------------------------------SC = O(d)
// vector<int> rotate_d_places(vector<int> &arr , int d)
// {
//     int n = arr.size();

//     // keeping the d in the range of n : as for the every multiple of d , the array will be in its original form
//     d= d%n;

//     vector<int>temp;

//     // step 1 : putting the elements in temp2 ----------------O(d)
//     for(int i=0;i<d;i++)
//     {
//         temp.push_back(arr[i]);
//     }

//     // step 2 : shifting the elements in the array -------------------------O(n-d) (as we are shifting n-d elements)
//     for(int i = d ; i<n ; i++)
//     {
//         arr[i-d] = arr[i];
//     }

//     // step 3 : putting the elements back in arr from temp-----------------------O(d) (as we are putting back d elements)
//     for(int i = n-d ; i<n ;i++)
//     {
//         arr[i] = temp[i-(n-d)];
//     }

//         return arr;
// }


// OPTIMAL SOLUTION
// TC = O(2n)
// SC = O(1)
void Reverse(vector<int> & arr , int start , int end)
{
    while(start<=end)
    {
       int temp = arr[start];
       arr[start] = arr[end];
       arr[end] = temp;
       start++;
       end--;
    }
}


vector<int> rotate_d_places(vector<int> &arr , int d)
{
       int n = arr.size();
        Reverse(arr , 0 , d-1 ); // -------------------O(d)
        Reverse(arr , d, n-1 );  // -------------------O(n-d)
        Reverse(arr , 0 , n-1);   //------------------O(n)

        return arr;
}



int main()
{
    vector<int>arr = {1,2,3,4,5};
    int d;
    cout<<"\nnter the dth place ";
    cin>>d;
    vector<int> nums = rotate_d_places(arr , d);
    cout<<"\nafter rotating the array by "<<d<<" places ";
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }

    return 0;
}