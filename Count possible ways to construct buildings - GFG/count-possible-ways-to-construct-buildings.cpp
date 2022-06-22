// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	const int mod=1e9+7;
	int TotalWays(int n){
    int prev=1; int sprev=1; 
    int cur;
    for(int i=2 ; i<=n+1 ; i++)
     { cur = (0LL+prev+sprev)%mod; 
       sprev=prev; prev=cur;}
    return (1LL*prev*prev)%mod ;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends