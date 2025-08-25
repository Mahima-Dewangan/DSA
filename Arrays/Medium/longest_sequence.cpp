#include<bits/stdc++.h>
using namespace std;
// Brute force 
// TC = O(n^2)
// SC = O(1)
// bool ls(vector<int> arr , int y)
// {
//     int n = arr.size();
//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]== y)
//         {
//             return true;
//         }

//     }
    
//         return false;
// }
// int longest_consecutive_seq(vector<int> arr)
// {
//       int longest = 1;
//     int n = arr.size();
//     for(int i = 0 ;i<n;i++)
//     {
//         int x = arr[i];
//         int cnt =1;

//         while(ls(arr , x+1) == true)
//         {
//             x = x+1;
//             cnt = cnt +1;
//         }

//         longest = max(cnt , longest);
//     }

//     return longest;
// }


// BETTER SOLUTION
// TC = O(n log n + n)
// SC =O(1)
// int longest_consecutive_seq(vector<int>arr)
// {
//     sort(arr.begin() , arr.end());  //------------------------------O(n log n)
//     int n = arr.size();
//     int longest = 1;
//     int cnt = 0;
//     int last_smaller = INT_MIN;

//     for(int i =0;i<n;i++)  //---------------------------------O(n)
//     {
//         if(arr[i]-1 == last_smaller)
//         {
//             cnt+=1;
//             last_smaller = arr[i];
//         }

//         else if(arr[i] != last_smaller)
//         {
//             cnt = 1;
//             last_smaller = arr[i];
//         }

//         longest = max(cnt , longest);
//     }

//     return longest;

// }


// OPTIMAL APPROACH
// TC = O(3n)
// SC = O(n)

int longest_consecutive_seq(vector<int>arr)
{
    int n= arr.size();
    if(n==0) return 0;

    int longest = 1;
    unordered_set<int> st;
    // inserting all element into the set
    for(int i=0;i<n;i++)
    {
        st.insert(arr[i]);
    }

    for(auto it:st)
    {
        // if the element is the starting point
        if(st.find(it-1)==st.end())  //the preve ele not present in the set
        {
             int cnt=1;
            int x = it;
            while(st.find(x+1)!= st.end()) //when the next elment is present
            {
                cnt = cnt +1;
                x=x+1;
            }
            longest = max(longest , cnt);

        }
    }

    return longest;
}


int main()
{
    vector<int>arr = { 100,4,200,1,3,2};
    cout<<"\nthe length of the longest consecutive sequence : "<<longest_consecutive_seq(arr);
    return 0;
}