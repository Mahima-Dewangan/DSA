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
         int n= arr.size();
        vector<int>nums(n);
        for(int i=n-1;i>=0;i--)
        {
        while(!st.empty() && st.top()<=arr[i])
        {
            st.pop();
        }

        if(st.empty())
        {
            nums[i]=-1;
        }
        else
        {
            nums[i]=st.top();
        }

        st.push(arr[i]);
    }

    return nums;

    }

};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Stack s;
    vector<int> result = s.nextGreaterElement(arr);

    cout << "Next Greater Elements:\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}




