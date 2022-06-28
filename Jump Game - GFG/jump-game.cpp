// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int a[], int n) {
        // code here
        vector<bool> dp(n+1, false);
        dp[n-1] = true, dp[n] = true;
        
        for(int ind=n-1;ind>=0;ind--){
            for(int jump=1;jump<=a[ind];jump++){
                if(dp[jump+ind])     {dp[ind] = true; break;}
            }
        }
        
        if(dp[0])    return 1;
        return 0;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends