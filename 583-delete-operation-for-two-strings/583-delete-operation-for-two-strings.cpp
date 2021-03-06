class Solution {
public:
int minDistance(string word1, string word2) {
int n=word1.size();
int m=word2.size();
int dp[n+1][m+1];
memset(dp, 0, sizeof(dp));
for(int i=1;i<n+1;i++){
for(int j=1;j<m+1;j++){
if(word1.at(i-1)==word2.at(j-1)){
dp[i][j]=1+dp[i-1][j-1];
}
dp[i][j]=max(dp[i][j], max(dp[i][j-1], dp[i-1][j]));
}
}
int ans=n+m-2*dp[n][m];
return ans;
}
};