// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
  const int CHAR=256;
    long long findRank(string str) {
        long long res=1;
        long long n=str.length();
        long long mul=fact(n);
        long long count[CHAR]={0};
        for(int i=0;i<n;i++)
         count[str[i]]++;
        for(int i=1;i<CHAR;i++)
         count[i]+=count[i-1];
        for(int i=0;i<n-1;i++)
        {
            mul=mul/(n-i);
            res=res+count[str[i]-1]*mul;
            for(int j=str[i];j<CHAR;j++)
             count[j]--;
        }
        return res;
    }
    
    long long fact(int n)
    {
        return (n == 1 || n == 0) ? 1 : fact(n - 1) * n;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends