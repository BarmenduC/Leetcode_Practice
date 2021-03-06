class Solution {
public:
    const long int M= 1e9+7;

// memoization 
int solve(int i, int j ,int k,int m,int n,vector<vector<vector<int>>>&dp){
    
    if(i<0||j<0||j>=n||i>=m)return 1; // if the condition approved the we got 1 ans
    if(k==0)return 0; // if  k maxmove get over nothing left so 0 
    
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    
   //Exploring all the ways 
     
    int up= solve(i-1,j,k-1,m,n,dp)%M;// going up 
     
    int down = solve(i+1,j,k-1,m,n,dp)%M; // going down 
    
    int right =  solve(i,j+1,k-1,m,n,dp)%M; //  going right
    
    int left= solve(i,j-1,k-1,m,n,dp)%M; // going left 
    
    return dp[i][j][k]=(up%M+down%M+left%M+right%M)%M; // adding the all the ways 
}
int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    
    vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1))); // 3d dp 
    
    return solve(startRow,startColumn,maxMove,m,n,dp);
}
};
