// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
   string LCP(string strs[], int n)
   {
       // code here
       sort(strs,strs+n);
       string a=strs[0];
       string b=strs[n-1];
       string ans="";
       for(int i=0;i<strs[0].length();i++)
       {
           if(a[i]==b[i])
           {
               ans+=a[i];
           }
           if(a[i]!=b[i])
           {
               break;
           }
       }
       if(ans=="")
       return "-1";
       return ans;
      
   }
};

// { Driver Code Starts.

int main() 
{

	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}  // } Driver Code Ends