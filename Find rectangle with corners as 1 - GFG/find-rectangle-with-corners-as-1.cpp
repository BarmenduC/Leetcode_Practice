// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
#include <unordered_map>
#include <unordered_set>
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool ValidCorner(const vector<vector<int> >& matrix)
    {
        // Your code goes here
       int rows = matrix.size();
       if (rows == 0)
           return false;
       int columns = matrix[0].size();

       for (int y1 = 0; y1 < rows; y1++)
           for (int x1 = 0; x1 < columns; x1++)

                if (matrix[y1][x1] == 1)
                    for (int y2 = y1 + 1; y2 < rows; y2++)
                       for (int x2 = x1 + 1; x2 < columns; x2++)
                           if (matrix[y1][x2] == 1 && matrix[y2][x1] == 1 && matrix[y2][x2] == 1)
                               return true;
       return false;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int row, col;
        cin>> row>> col;

        vector<vector<int> > matrix(row);
            
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        if (ob.ValidCorner(matrix)) 
            cout << "Yes\n"; 
        else
            cout << "No\n"; 
    }

    return 0;
} 


  // } Driver Code Ends