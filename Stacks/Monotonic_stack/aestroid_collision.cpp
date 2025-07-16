#include<iostream>
// #include<stack>
#include<list>
#include<vector>
using namespace std;

class List
{
    public:
    list<int>st;
    vector<int>aestroid_collide(vector<int>aestroids)
    {
        int n= aestroids.size();
        for(int i=0;i<n;i++)
        {
            if(aestroids[i]>0)
            {
                st.push_back(aestroids[i]);
            }
            else
            {
                while(!st.empty() && st.back()>0 && st.back()< abs(aestroids[i]))
                {
                    st.pop_back();
                }

                if(!st.empty() && st.back()==abs(aestroids[i]))
                {
                    st.pop_back();
                }

                else if(st.empty() || st.back()<0)
                {
                    st.push_back(aestroids[i]);
                }

            }
        }

         return vector<int>(st.begin(), st.end());
    }
};


int main()
{
    int n;
    cout<<"nter the number of elements";
    cin>>n;
    cout<<"\nenter the "<<n<<" elements";
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    List obj;
    vector<int>result = obj.aestroid_collide(arr);
    for( auto i:result)
    {
         cout<<i<<" ";
    }

    cout<<endl;

    return 0;
    
}