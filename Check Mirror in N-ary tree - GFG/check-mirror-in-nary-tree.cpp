// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int check(int u, vector<vector<int>>& adjA, vector<vector<int>>& adjB) {
        if(adjA[u].size() != adjB[u].size()) return 0;
        
        for(int i=0; i<adjA[u].size()/2; i++)
            if(adjA[u][i] != adjB[u][adjB[u].size()-1-i])
                return 0;
        
        for(int v : adjA[u])
            if(!check(v, adjA, adjB))
                return 0;
                
        return 1;
    }
    
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        vector<vector<int>> adjA(n+1), adjB(n+1);
        for(int i=0; i<2*e; i+=2) {
            adjA[A[i]].push_back(A[i+1]);
            adjB[B[i]].push_back(B[i+1]);
        }
        
        return check(1, adjA, adjB);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends