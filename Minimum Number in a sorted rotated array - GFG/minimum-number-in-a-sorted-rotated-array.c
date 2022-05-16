// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C


//Function to find the minimum element in sorted and rotated array.
int minNumber(int arr[], int low, int high)
{
   if(high<low)return arr[0];
   if(high==low)return arr[low];
   
   int mid = low + (high-low)/2;
   
   if( mid<high && arr[mid+1] < arr[mid])
     return arr[mid+1];
    
   if(mid>low && arr[mid] < arr[mid-1])
    return arr[mid];
    
    if(arr [high]>arr[mid])
    return minNumber(arr,low,mid-1);
    return minNumber(arr,mid+1,high);
    
}

// { Driver Code Starts.

int main()
{
	
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int a[n];
		for(int i=0;i<n;++i)
			scanf("%d", &a[i]);	
	
		printf("%d\n", minNumber(a,0,n-1) );
	}
	return 0;
}  // } Driver Code Ends