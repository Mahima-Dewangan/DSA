#include<iostream>
using namespace std;
int sqrt(int n)
{
    int low = 1;
    int high = n;
    while(low<=high)
    {
         int mid = low + (high-low)/2;
        if(mid*mid<=n)
        {
            low=mid+1;
        }

        else
        {
            high=mid-1;
        }
    }
    return high;
}

int main()
{
    int n ;
    cout<<"\nter th no you want to find the square root of ";
    cin>>n;
    cout<<"\nthe square root of the number is"<<sqrt(n);
    return 0;
}