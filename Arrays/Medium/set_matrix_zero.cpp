#include <bits/stdc++.h>
using namespace std;

// BRUTE  FORCE 
// TC = O(n^3)   : O(n*m)*(n+m) + (n*m)
// SC = O(1)

// void  set_row(vector<vector<int>> &matrix , int n , int m , int i)
// {
//     for(int j =0;j<m;j++)
//     {
//         if(matrix[i][j]!=0)
//         matrix[i][j]=-1;
//     }
// }

// void set_col(vector<vector<int>> &matrix , int n , int m , int j)
// {
//     for(int i=0;i<n;i++)

//     {
//         if(matrix[i][j]!=0)
//         matrix[i][j]= -1;
//     }
// }
// vector<vector<int>> set_zero(vector<vector<int>> &matrix, int n, int m) // n = no of rows , m = no of columns
// {

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m ; j++)
//         {
//             if(matrix[i][j]==0)
//             {
//                 set_row(matrix , n , m , i);
//                 set_col(matrix , n , m , j);
//             }
//         }
//     }



//     // finally , marking all -1 as 0

//     for(int i =0;i<n;i++)
//     {
//         for(int j=0;j<m ;j++)
//         {
//            if(matrix[i][j] == -1)
//            {
//             matrix[i][j]=0;
//            }
//         }
//     }

//     return matrix;
// }


// BETTER SOLUTION 
// TC = O(2*n*m)
// SC = 0(n+m)

// vector<vector<int>> set_zero(vector<vector<int>> &matrix , int n , int m)
// {
//     vector<int>row(n);
//     vector<int>col(n);
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0 ;j<m ; j++)
//         {
//             if(matrix[i][j]==0)
//             {
//                 row[i]=1;
//                 col[j]=1;
//             }
//         }
//     }


//     for(int i =0;i<n;i++)
//     {
//         for(int j =0;j<m ; j++)
//         {
//             if(col[j] || row[i])
//             {
//                 matrix[i][j]=0;
//             }
//         }
//     }
// }



// OPTIMAL SOLUTION
// TC =
// SC = 
vector<vector<int>> set_zero(vector<vector<int>> &matrix , int n ,int m)
{
    int col0 = 1;
    for(int i=0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if(matrix[i][j]==0)
            {
                // mark the ith row
                matrix[i][0]=0;
                
                // mark the jth col
                if(j!=0)
                {
                    matrix[0][j]=0;
                }
                else
                {
                    col0 =0;
                }

            }
        }
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1 ;j<m;j++)
        {
            if(matrix[i][j]!=0) 
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }

    if(matrix[0][0]==0)
    {
        for(int j=0;j<m;j++)
        {
            matrix[0][j]=0;
        }
    }

    if(col0 ==0)
    {
        for(int i =0;i<n ;i++)
        {
            matrix[i][0]=0;
        }
    }

    return matrix;
}
int main()
{
    vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 0, 0, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = set_zero(matrix , m ,n);
    cout<<"\nthe final matrix is ";

    for(int i = 0 ;i<n ; i++)
    {
        for(int j =0 ; j<m ;j++)
        {
            cout<<matrix[i][j]<<" ";
        }

        cout<<"\n";
    }

    return 0;
}