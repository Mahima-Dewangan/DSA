#include<bits/stdc++.h>
using namespace std;

// The problem can be solved using both BFS and DFS , but as the question says that we need the 
// minimum amount of time , so we will go with the BFS algorithm

// Intuition : There can be more than one starting point depending on the no of the 
// no of rotten oranges given initially

// we will queue data structure

// 0-empty cell
// 1-fresh orange 
// 2-rotten orange

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();  //no of rows
    int m = grid[0].size(); //no of cols

    queue<pair<pair<int , int> , int>> q ; //queue stroing data in the format : {{r,c} ,t}
    vector<vector<int>> vis(n, vector<int>(m, 0)); //2d visited array;

    // storing the initially rotten oranges into the queue and also in the visited array as 2 and the one which are not rottem mark them as 1

    for(int i =0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2) 
            {
            q.push({{i , j},0});
            vis[i][j]=2; //rotten oranges marked as 2 in the vis array
            }

            else 
            {
                vis[i][j]=0;  //non rotten oranges marked as 0 in the vis array
            }
        }
    }


  int tm =0; //to get the time 
  int drow[]={-1 , 0, 1,0}; //to get the neighbouring rows of the curent rotten oranges {top , right , bottom ,left}
  int dcol[]={0,1,0,-1};  //to get the neighbouring cols of the current rotten oranges {top , right , bottom ,left}
  while(!q.empty())
  {
      int r = q.front().first.first;
      int c = q.front().first.second;
      int t = q.front().second;
      tm = max(tm ,t);
      q.pop();

      for(int i=0;i<4;i++)  //there are 4 neighbours as top , right , bottom , left
      {
        int nrow = r + drow[i];  //nrow = neightbouring row 
        int ncol = c + dcol[i];  //ncol = neighbouring col

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&     
            vis[nrow][ncol]!=2 && grid[nrow][ncol]==1 )  //here we are checking if the nrow  and ncol lies within the range of the grid,
                                                         // the visited of the neighbouring orange is not already rotten
                                                         //the neighbouring orange is fresh

        {
            q.push({{nrow , ncol}, t+1});
            vis[nrow][ncol]=2;

        }
      }

   }

      //if not all the oranges are rotten
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]!=2 && grid[i][j]==1)
            {
                return -1;
            }
        }
      }

      return tm;

}


int main()
{
    
        vector<vector<int>> v{ {2,1,1} , {1,1,0} , {0,1,1} } ;
        int rotting = orangesRotting(v);
        cout<<"Minimum Number of Minutes Required "<<rotting<<endl;
        
    return 0;
}