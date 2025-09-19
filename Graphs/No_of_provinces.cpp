#include<bits/stdc++.h>
using namespace std;

void dfs( int node , vector<vector<int>> & adjLs , vector<int> &vis)
{
    vis[node]=1;
    for(auto it : adjLs[node])
    {
        if(!vis[it])
        {
            dfs(it , adjLs , vis);
        }
    }
}


int findProvinces( vector<vector<int>> &isConnected)
{
    int n = isConnected.size();

    // converting the adjacency matrix into the adjacency list

    vector<vector<int>> adjLs(n); //adjacency list

    for(int i =0; i<n ;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(isConnected[i][j]==1 && i!=j)
            {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }


    vector<int>vis(n ,0);
    int cnt =0;

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            cnt++;
            dfs(i , adjLs , vis);
        }
    }

    return cnt;
}

int main()
{
    vector<vector<int>> isConnected = {{1,1,0} ,{1,1,0} , {0,0,1}};
    cout<<"\n the no of provinces are : "<<findProvinces(isConnected);
    return 0;
}