// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

int countDigits(int n)
{
   int count = 1;
   if(n==0)
   {
       return 1;
   }
   if(n<10)
   {
       return 1;
   }
   else
    count+=countDigits(n/10);
return count;
}

// { Driver Code Starts.

int main() {
	int T;
	
	//taking testcases
	scanf("%d", &T);
	while(T--)
	{
	    int n;
	    
	    //taking number n
	    scanf("%d", &n);
	    
	    //calling countDigits
	    printf("%d\n", countDigits(n));
	    
	    
	}
	return 0;
}
  // } Driver Code Ends