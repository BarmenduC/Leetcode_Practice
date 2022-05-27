// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> numAndDen(int n, int d) {
        // code here
        long double val=(long double)n/(long double)d;
       
        int num=val*10000;
        int den=10000;
        
        
        long double mx=-1;
        vector<int>ans(2);
        
        long double temp=(long double)num/(long double)den;
        do
        {
            
            if(temp<val)
            {
                if(temp>mx)
                {
                    mx=temp;
                    ans[0]=num;
                    ans[1]=den;
                    
                }
                den--;
                
            }
            else
            {
                
                num--;
                
            }
            temp=(long double)num/(long double)den;
            
        }
        while(temp>=0);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin >> n >> d;
        Solution ob;
        vector<int>ans=ob.numAndDen(n,d);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends