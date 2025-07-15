#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Stack
{
    public:
    stack<int> st;
    vector<int> nextGreaterElement(vector<int>arr)
    {
        int n=arr.size(); vector<int>ans(n);
        for(int i=2*n-1;i>=0;i--)
        {
             while(!st.empty() && st.top()<=arr[i%n])
             {
                st.pop();
             }
              if(i<n)
              {
             if(st.empty())
             {
                ans[i]= -1;
             }
             else{
                    ans[i]=st.top();
             }

             
            }
            st.push(arr[i%n]);
        }

        return ans;

    }
};

int main()
{
    int n;
    cout<<"\nnter the size of the array";
    cin>>n;
    vector<int>arr(n);

    cout<<"nter the "<<n<<"elements";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    Stack obj;
    vector<int>result = obj.nextGreaterElement(arr);

    cout<<"\nnext greater elements are:";
    for(auto i:result)
    {
        cout<<i<<" ";
    }

    cout<<endl;
    return 0;

}