#include<bits/stdc++.h>
using namespace std;

// Brute Force 
// TC = O(n1 log n) + O(n2 log n) + O(n1 +n2)-------when both the array contains distinct elements
// SC = O(n1 + n2)---[when both the arrays contains distinct elements(set)]  + O(n1 +n2) ---[to display the result(temp)]---
// vector<int> union_arr(vector<int>a1 , vector<int>a2)
// {

//     int a = a1.size();
//     int b = a2.size();
//     set<int>s;

//     for(int i=0;i<a;i++)------------------------------O(n1 log n)
//     {
//         s.insert(a1[i]);
//     }

//     for(int i=0;i<b;i++)------------------------------------O(n2 log n)
//     {
//         s.insert(a2[i]);
//     }

//     vector<int>temp;--------------------------(n1 + n2)
//     for(auto it:s)
//     {
//         temp.push_back(it);
//     }
//     return temp;

// }


// OPTIMAL SOLUTION
// TC = O(n1+n2)
// SC= O(n1+n2)-------------(for returning the result(temp))
vector<int> union_arr(vector<int> a1 , vector<int> a2)
{

    int a = a1.size(); int i=0;
    int b = a2.size(); int j=0;
    vector<int>temp;
    
    // when both array are pointing to some element in the array 
    while( i < a && j < b)
    {
        if(a1[i]<=a2[j])
        {
           if( temp.size() == 0 || temp.back() != a1[i] ) 
           {
            temp.push_back(a1[i]);
           
           }
           i++;
        }

        else
        {
            if(temp.size()== 0 || temp.back() != a2[j])
            {
                temp.push_back(a2[j]);
            }
            j++;
        }
}


while(j<b)
{
      if(temp.size()== 0 || temp.back() != a2[j])
            {
                temp.push_back(a2[j]);
            }
            j++;
}

while(i<a)
{
    if( temp.size() == 0 || temp.back() != a1[i] ) 
           {
            temp.push_back(a1[i]);
           
           }
           i++;

}

return temp;


}
int main()
{
    vector<int>a1 = {1,2,3,3,4,5,5};
    vector<int> a2={1,2,3,3,4,5,6,6,7};
    vector<int>nums = union_arr(a1 , a2);
    cout<<"\nafter union the array is ";
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }

    return 0;
}

