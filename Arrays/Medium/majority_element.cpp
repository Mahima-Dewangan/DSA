#include<bits/stdc++.h>
using namespace std;


// BRUTE FORCE TECHIQUE
// TC =O(n^2)
// SC =O(1)

// int majority_element(vector<int>arr)
// {
//     int n = arr.size();
    
    
//     for(int i=0;i<arr.size();i++) ------------------------------O(n)
//     {
//         int cnt=0;
//         for(int j=0;j<arr.size();j++) -------------------------------O(n)
//         {
//             if(arr[i]==arr[j])
//             {
//                 cnt++;
//             }
//         }

//         if(cnt > arr.size()/2)
//         {
//             return arr[i];
//         }
//     }

//     return -1;

// }




// BETTER SOLUTION   ---HASHMAP
// TC = O(n logn + n)
// SC = O(1)

// int majority_element(vector<int>arr)
// {
//     map<int , int>mpp;

//     for(int i=0;i<arr.size();i++)    //-------------O(n logn)
//     {
//         mpp[arr[i]]++;

//     }

//     for(auto i : mpp)     //-----------------O(n)
//     {
//         if(i.second > arr.size()/2)
//         {
//             return i.first;
//         }
//     }


//     return -1;
// }


// OPTIMAL SOLUTION
// TC = O(n) ---if the ques says that the majority element surely exists in the given array
// TC = O(2n)  --if the ques says that the majority element may or may not exist
// SC = O(1)

int majority_element(vector<int>arr)
{
    int cnt=0;
    int el;
    for(int i=0;i<arr.size();i++)    // ------------o(n)
    {
        if(cnt==0)
        {
            cnt=1;
            el = arr[i];
        }

        else if(arr[i]==el)
        {
            cnt++;
        }

        else
        {
            cnt--;
        }
    }

    // if the array may or may not contain the majority element : we need to verify
    for(int i=0;i<arr.size();i++)  // ---------------------o(n)
    {
        if(arr[i]==el)
        {
            cnt++;
        }

    }


    if(cnt > arr.size()/2)
    {
        return el;
    }

    return -1;
}



int main()
{
    vector<int> arr = {2,2,3,3,1,2,2};
    cout<<"\n the majority element is "<<majority_element(arr);
    return 0;
}