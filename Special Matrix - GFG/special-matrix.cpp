// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
int mod=1e9+7;
int FindWays(int n, int m, vector<vector<int>>blocked_cells){
    // Code here
    vector<vector<int>> ans(n+1,vector<int>(m+1,0));
    int k=blocked_cells.size();
    for(int i=0;i<k;i++)
    {
        ans[blocked_cells[i][0]][blocked_cells[i][1]]=-1;
        // cout<<blocked_cells[i][0]<<" "<<blocked_cells[i][1]<<endl;
    }
    ans[1][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(ans[i][j]==-1)
            ans[i][j]=0;
            else{
                ans[i][j]=(ans[i-1][j]+ans[i][j-1])%mod;
            }
           // cout<<ans[i][j]<<endl;
        }
    }
    return ans[n][m];
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends