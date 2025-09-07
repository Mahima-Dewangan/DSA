#include<bits/stdc++.h>
using namespace std;

// Adjacency matrix representation of the graph  ( UNDIRECTED GRAPH)
/*  two inputs will be given - no of nodes(n) and no of edges(m)
    REMEMBER : In a particular graph the no of nodes remain constant, where as you
    can keep incresing the no of edges

    So - The algorithm to represent the graph in the form of adjacency matrix
      Step 1 : You will be given a no of nodes and the no of edges
      Step 2 : Next , there will be m lines which will give you th edege between two nodes 
      Step 3 : you need to set that position as 1 in the adjacency matrix

TC = O(m)-----the no of edges
SC = O(n^2)
*/

int main()
{
    int n ,m ;
    cout<<"\nenter the no of nodes";
    cin>>n;
    cout<<"\nenter the no of edges";
    cin>>m;

    int adj[n+1][m+1];  //as i am naming the nodes starting from 1 and not from 0.


    // storing the graph
    for(int i = 1;i<=m;i++)
    {
        int u, v;

        cout<<"enter the nodes between which you want an edge";
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;

    }


    

    return 0;
}