// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 


 // } Driver Code Ends

class Solution
{
    public:
    int build_bridges(string str1, string str2)
    {int  m = str1.size();
    int n = str2.size();
    int matrix [m+1][n+1];
      matrix[0][0] = 0 ;  // -- > firstr part ( 0,0) =0 value ;
    for ( int i =1; i<=m ; i++){
        matrix[i][0]=0; // --> first row (i, 0) =0  value ;
    }
    for( int j =1; j<=n; j++)
    {
        matrix[0][j]=0 ; // --> first column is made zero ;
    }
    
    // ----->> Straight forward LCS algo for largest subsequences ........
    for ( int i =1; i<= m ; i++){
        for  (int j =1; j <=n; j++)
        {
            if ( str1[i-1] == str2[j-1])
            {matrix[i][j] = 1+matrix[i-1][j-1];
                
            }
            else {
                matrix[i][j]= max ( matrix[i-1][j] , matrix[i][j-1]);
            }
        }
    }
    return matrix[m][n];// returning the number of the largest subsequences form ...
    
    }
};
// { Driver Code Starts.
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        string str1,str2;
        cin >> str1 >> str2;
        Solution obj;
        cout<<obj.build_bridges(str1,str2)<<endl;
    } 
    return 0;
} 
  // } Driver Code Ends