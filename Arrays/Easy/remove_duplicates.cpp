#include<bits/stdc++.h>
using namespace std;

// Brute force--------------TC=O(n log n + n)

// int remove_duplicates(vector<int> &arr) {
//     set<int> st;
    
//     // Insert all elements into the set to remove duplicates
//     for (int i = 0; i < arr.size(); i++) {  // O(n)
//         st.insert(arr[i]);                  // O(log n)
//     }

//     // Put unique elements back into the array
//     int index = 0;
//     for (auto val : st) {                   // O(n)
//         arr[index] = val;
//         index++;
//     }

//     // Return new size
//     return index;
// }
// ---------------------------------------------------------------------------------------------------------------------
// OPTIMAL SOLUTION 
// TC = O(n)
int remove_duplicates(vector<int> &arr)
{
    int i=0;
    for(int j=1;j<arr.size();j++)
    {
        if(arr[j]!=arr[i])
        {
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
}


int main() {
    vector<int> arr = {1,1,2,2,2,3,3};
    int newSize = remove_duplicates(arr);

    cout << "Unique elements: "<<newSize;
    return 0;
   
}


