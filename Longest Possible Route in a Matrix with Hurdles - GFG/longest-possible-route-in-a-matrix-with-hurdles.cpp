// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
    int n, m;
    int row[4] = {0, -1, 0, 1}, col[4] = {-1, 0, 1, 0};
    bool vis[11][11];
public:
    int rec(int xs, int ys, int xd, int yd, vector<vector<int>> mat){
        if(xs == xd && ys == yd)    return 0;
        vis[xs][ys] = true;
        int res = -1e9;
        for(int i=0;i<4;i++){
            int x = xs+row[i], y = ys+col[i];
            if(x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1 && !vis[x][y]){
                res = max(res, 1+rec(x, y, xd, yd, mat));
            }
        }
        vis[xs][ys] = false;
        return res;
    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        if(matrix[xs][ys] == 0 or matrix[xd][yd] == 0)    return -1;
        n = matrix.size(), m = matrix[0].size();
        memset(vis, false, sizeof(vis));
        int val = rec(xs, ys, xd, yd, matrix);
        if(val == -1e9)  return -1;
        return val;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends