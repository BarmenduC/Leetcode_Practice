class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if(s3.size()!=(s1.size()+s2.size())) return false;
		bool dp[101][101] = {false};
		dp[0][0] = true;
		for(int i = 0;i<s1.size()+1;i++){
			for(int j = 0;j<s2.size()+1;j++){
				if(i<s1.size() && s1[i] == s3[i+j] && dp[i][j]) dp[i+1][j] = true;
				if(j<s2.size() && s2[j] == s3[i+j] && dp[i][j]) dp[i][j+1] = true;
			}
		}
		return dp[s1.size()][s2.size()];
	}
};