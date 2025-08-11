#include<bits/stdc++.h>
using namespace std;

// Brute force approach
// STEP 1 : SORT THE ARRAY --------------- 0( n log n)
// STEP 2 :  largest = arr[n-1]
//           second_largest = -1;
// for(int i= n-1 ; i>=0 ; i--)----------------------- O(n)
// {
 //    if(arr[i]!=largest)
//  {       
//       second_largest =arr[i];
//       break;
//  }
// }
// return second_largest;
// TC = O(nlog n + n)


// Better solution

// int second_largest(vector<int> arr)
// {
//     // find largest element  ---------------------------o(n)
//     int largest = arr[0];

//     for(int i=0;i<arr.size();i++)
//     {
//         if(arr[i]>largest)
//         {
//             largest = arr[i];
//         }
//     }

   


//     // find the second largest; --------------------------------o(n)
//     int second_largest = -1;
//     for(int i=0;i<arr.size();i++)
//     {
//             if(arr[i] > second_largest &&  arr[i]!=largest)
//             {
//                 second_largest = arr[i];
                
//             }

//     }

//     return second_largest;
// }
// TC = O(2n)


// OPTIMAL SOLUTION--------------------TC = O(n)
int second_largest(vector<int> arr)
{
    int largest = arr[0];
    int second_largest = -1;
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]>largest)
        {
            second_largest = largest;
            largest = arr[i];
        }

        else if(arr[i]<largest && arr[i]>second_largest)
        {
            second_largest = arr[i];
        }
    }

    return second_largest;

}

int main()
{
    vector<int> arr = {2,4,5,70,8,90};
    cout<<"\nthe second largest element is "<<second_largest(arr);
    return 0;
}

