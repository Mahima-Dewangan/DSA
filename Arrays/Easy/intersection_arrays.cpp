#include<bits/stdc++.h>
using namespace std;


// OPTIMAL SOLUTION 
// TC = O(n1+n2)
// SC = O(1)
vector<int> intersection_arr(vector<int>a , vector<int>b)
{
    int n1 = a.size();
    int n2 = b.size();
    vector<int>arr;
    int i=0;
    int j=0;
    while( i<n1 && j<n2)
    {
        if(a[i]< b[j])
        {
            i++;
        }

        else if(a[i]>b[j])
        {
            j++;
        }
        else
        {

           
             arr.push_back(a[i]);
             i++;j++;
                
        }
    }

    return arr;
}

int main()
{
    vector<int> a= {1,2,3,3,4,5,6,7};
    vector<int> b= {1,3,3,3,4,8};
    vector<int>nums=intersection_arr(a , b);
    cout<<"\nthe intersection of the array is ";
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }

    return 0;
}
