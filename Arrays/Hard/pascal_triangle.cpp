#include<bits/stdc++.h>
using namespace std;

// pascal triangle looks like
/*                          1
                        1       1
                    1       2       1
                1      3        3       1
             1     4        6       4       1
         1      5      10       10      5      1
 */


//  TYPE 1 : TO FIND THE ELEMENT AT THE POSITION WITH RTH ROW AND CTH COL 
//  intuition : to find the nCr  where n = R-1 and r = C-1;
// TC = O(n)
   int nCr( int n , int r)
   {
      long long res = 1;
      for(int i=0;i<r;i++)
      {
        res= res * (n-i);
        res = res/ (i+1);
      }

      return res;
   }

//   TYPE 2 : TO PRINT ANY ROW N OF THE PASCAL TRIANGLE 
// remember : the Nth row will contain N elements
// BETTER SOLUTION : 
// TC = O(N*r)
// for(int c=0;c<=N;c++) --------------------O(N)
// {
//     print(nCr(n-1 , c-1)); ----------------O(r)
// }

// OPTIMAL SOLUTION
// TC = O(N)
/* res = 1;
   print(res)
   for(int i =1;i<N;i++)
   {
      ans = ans * (N-i);
      ans = ans / (i);

      print(ans);
   }
*/
