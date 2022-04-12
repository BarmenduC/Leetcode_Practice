// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int dp[101][10001];

   int helper(vector<int> nums,int i,int am){
       if(am < 0) return (INT_MAX-1);
       if(am == 0) return (0);
       if(i < 0) return (INT_MAX-1);
       
       if(dp[i][am] != -1) return (dp[i][am]);
       
       if(nums[i] <= am){
           return dp[i][am] = min(1+helper(nums,i,am-nums[i]),helper(nums,i-1,am));
       }
       return dp[i][am] = helper(nums,i-1,am);
   }
   
int MinCoin(vector<int>nums, int amount)
{
    memset(dp,-1,sizeof(dp));
    int ans = helper(nums,nums.size()-1,amount);
    return ans >= INT_MAX-1 ? -1 : ans;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends