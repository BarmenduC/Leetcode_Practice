// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   unordered_map <int,vector<int>> umap;
   int sol(int N,int p)
   {
       int ans=0;
       for(auto c:umap[p])
       {
           ans=max(ans,sol(N,c));
       }
       return ans+1;
   }
   int findHeight(int N, int arr[]){
       for(int i=0;i<N;i++)
       {
           umap[arr[i]].push_back(i);
       }
       return sol(N,-1)-1;
   }
};
// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.findHeight(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends