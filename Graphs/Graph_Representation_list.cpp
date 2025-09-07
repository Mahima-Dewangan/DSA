#include<bits/stdc++.h>
using namespace std;

// Graph Representation using : ADJACENCY LIST (undirected graph)
/*
        way to create an adjacency list = vector<int>adj[n+1];
TC = O(m)
SC=O(2*|E|)
*/
int main()
{
    int n , m;
    cout<<'\nenter the no of nodes';
    cin>>n;
    cout<<"\n enter the no of edges";
    cin>>m;

    vector<int>adj[n+1];

    // storing the graph
    for(int i=1 ;i<=m;i++)
    {
        int u,v;
        cout<<"\nenter the nodes between which you want the edges ";
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);   //for a directed we don't need this line , assuming the direction is u->v  , so SC for a directed graph O(|E|)

    }

    return 0;

}
