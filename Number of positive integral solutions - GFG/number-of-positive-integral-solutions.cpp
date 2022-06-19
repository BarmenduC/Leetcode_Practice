// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    long posIntSol(string s)
   {
       int m=s.size();
       int k=1;
       int n;
      for(int i=0; i<m; i++){
          if(s[i]=='+') k++;
          else if(s[i]=='='){
              if(i==m-2) {
                  n=s[i+1]-'0';
                  break;
              }
              else{
                  n = (s[i+1]-'0')*10 + s[i+2]-'0';
                  break;
              }
          }
      }
      if(k>n) return 0;
      if(k==1 && m>3) return 1;
   //   for finding  non-negative sol (n+k-1)C(k-1)
   //   for finding  positive sol (n-1)C(k-1);
      n--;
      k--;
      
   //   find (n)C(k);
      long long int ans=1;
      int minval = min(k,n-k);
      n++;
      for(int i=1;i<=minval;i++){
         ans*= (n-i);
         ans/=i;
      }
      return ans;
   }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends