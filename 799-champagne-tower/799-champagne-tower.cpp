class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<float>> dp(102,vector<float> (102,0));
        dp[0][0]=poured;
        
        for(int i=0;i<query_row;i++)
        {
            for(int j=0;j<=i;j++)
            {
                float extra=(dp[i][j]-1)/2.0;
                cout<<extra;
                if(extra>0)
                {
                    dp[i+1][j]+=extra;
                    dp[i+1][j+1]+=extra;
                }
            }
        }
        
        
        
        if(dp[query_row][query_glass]>1)
            return 1;
        return dp[query_row][query_glass];
        
    }
};