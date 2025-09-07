#include<bits/stdc++.h>
using namespace std;

// we are given a zero based indexing of the nodes of the graph
// TC = O(n) + O(2|E|)
// SC = O(3n) = O(n)--for visited array (vis(n))  , O(n) for queue , O(n) for bfs vector
vector<int> bfsOfGraph(int n , vector<int>adj[])  // here n is no of nodes and the second parameter is the adjacency list
{
    int vis[n]={0};
    queue<int>q;
    vector<int>bfs;
    vis[0]=1;
    q.push(0);
   

    while(!q.empty())  //---------------O(n) , where n = no of nodes
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it : adj[node])  //--------------it will traverse the adjacency list  i .e 2|E| times 
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }


        }

    }


    return bfs;

}