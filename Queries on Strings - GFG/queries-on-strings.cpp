// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {

public:
vector<int>SolveQueris(string str, vector<vector<int>>Query){
    vector<vector<int>>dp;
    vector<int> res;
    dp.resize(str.size()+1, vector<int>(str.size()+1, 0));
    int n = str.size();
    for(int i=0; i<n; i++){
        unordered_map<char, int> mp;
        for(int j = i; j<n; j++){
            mp[str[j]] = true;
            dp[i+1][j+1] = mp.size();
        }
    }
    for(auto q : Query){
        res.push_back(dp[q[0]][q[1]]);
    }
    return res;
}
};
// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends