// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long checkPrime(long long num){
       for(int j = 2;j<=sqrt(num);j++){
           if(num % j == 0){
               return 1;
           }
       }
       return num;
   }

   long long primeProduct(long long L, long long R){
       long long pro = 1;
       long long i = L;
       while(i<=R){
           pro = pro * checkPrime(i)%1000000007;
           i++;
       }
       
       return pro;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends