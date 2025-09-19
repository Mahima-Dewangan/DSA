#include<bits/stdc++.h>
using namespace std;

void dfs(int start , int vis[] , vector<int>adj[] ,vector<int>ans )
{
    vis[start]=1;
    ans.push_back(start);

    for(auto it : adj[start])
    {
        if(!vis[it])
        {
            dfs(it , vis , adj , ans);
        }
    }

}
vector<int>dfsOfGraph(int n ,vector<int>adj[])
{
    vector<int>ans;
    int vis[n]={0};

    int start =0;
    
    dfs(start , vis , adj , ans );
    return ans;

}