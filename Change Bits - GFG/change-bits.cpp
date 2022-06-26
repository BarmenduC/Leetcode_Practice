// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
 public:
   vector<int> changeBits(int N) {
       // code here
       vector<int> v;
       int newn=pow(2,int(log2(N))+1)-1;
       int num = newn- N;
       v.push_back(num);
       v.push_back(newn);
       return v;
       
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends