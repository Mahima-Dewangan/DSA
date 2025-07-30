#include<bits/stdc++.h>
using namespace std;
int nth_root( int n , int m)
{
    int low =1;
    int high = m;
    while(low<=high)
    {
        int mid= low + (high-low)/2;
        if(pow(mid,n)==m)
        {
            return mid;
        }

        else if(pow(mid , n)>m)
        {
            high = mid-1;
        }

        else
        {
            low = mid+1;
        }
        


    }

    return -1;
}

int main()
{
    int m ,n ;
    cout<<"nter the no ";
    cin>>m;
    cout<<"\nnter the root you want to find";
    cin>>n;
    cout<<"\n "<<n<<"  root of  "<<m<<" is "<<nth_root(n,m);
    return 0;
}