// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        int n = matrix.size(), m = matrix[0].size();
        int di[4] = {-1,0,1,0}, dj[4] = {0,1,0,-1};
        int r = 1;
        
        pair<int, int> res;
        int i=0, j=0;
        while(i>=0 and i<n and j>=0 and j<m) {
            res = {i,j};
            if(matrix[i][j] == 1) {
                matrix[i][j] = 0;
                r = (r+1)%4;
            }
            i += di[r];
            j += dj[r];
        }
        
        return res;
    }
};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends