// { Driver Code Starts
//Initial Template for C++


#include <iostream>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
int sum=0;
class Solution{
  public:
    //Complete this function
    
int digitalRoot(int n)
{
    if(n<10)
   	return n;
   
   if(n%9 == 0)
   	return 9;
   else
   	return n%9;
}   
        
};

// { Driver Code Starts.


int main() {
	int T;
	cin>>T;//taking testcases
	while(T--)
	{
	    int n;
	    cin>>n;//taking number n
	    
	    //calling digitalRoot() function
	    Solution obj;
	    cout<<obj.digitalRoot(n)<<endl;
	    
	    
	}
	return 0;
}  // } Driver Code Ends