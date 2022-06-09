// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b)
    {
        return a.second>b.second;
    }
    int maxCoins(int A[], int B[], int T, int N) {
        pair<int,int> st[N];
        for(int i=0;i<N;i++)
            st[i]={A[i],B[i]};
        sort(st,st+N,cmp);
        
        int v=0;
        
        for(int i=0;i<N;i++)
        {
        
            if(st[i].first<=T)
            {
                v+=st[i].second*st[i].first;
                T-=st[i].first;
            }
            else
            {
                v+=st[i].second*T;
                break;
            }
        }
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends