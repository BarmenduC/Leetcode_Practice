// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
 int minRepeats(string A, string B) {
       // code here
       int count=1;
       int repeat=B.length()/A.length();
       string res=A;
       for(int i=1;i<=repeat+2;i++){
           if(A.find(B)!=string::npos){
               return count;
               break;
           }
           A+=res;
           count++;
       }
       return -1;
       
       
   }
};

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends