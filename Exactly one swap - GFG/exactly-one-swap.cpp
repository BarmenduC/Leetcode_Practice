// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
   long long countStrings(string S)
   {
       long long umap[26]={0};
       long long n=S.length();
       long long count=0;
       int g=0;
       for(auto c:S)
           umap[c-97]++;
       int i=1;
       for(auto c:S)
       {
           if(umap[c-97]>1)
           g=1;
         umap[c-97]-=1;
         count+=n-i-umap[c-97];
         i+=1;
       }
       return count+g;
   }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends