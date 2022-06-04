// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long buzzTime(long n, long m, long l, long h[], long a[])
   {
      long cons = pow(10, 10);
      long lo = 0 , hi = cons,ans = LONG_MAX;
      while(lo <= hi)
      {
          long mid = (hi-lo)/2+lo;
          if(pos(mid,n,m,l,h,a))
           {
               ans = mid;
               hi = mid-1;
           }
           else{
               lo = mid+1;
           }
      }
      return ans;
   }
   bool pos(long mid,long n, long m, long l, long h[], long a[])
   {
       long sum = 0,x = 0;
       for(int i = 0; i < n; i++)
       {
           x = h[i]+mid*a[i];
           if(x >= l)
           {
               sum += x;
           }
       }
       if(sum >= m) return true;
       return false;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends