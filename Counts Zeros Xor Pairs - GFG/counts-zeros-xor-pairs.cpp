// { Driver Code Starts
// C++ program to find number 
// of pairs in an array such
// that their XOR is 0
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the
// count
long long int calculate(int a[], int n);

// Driver Code
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
	  int n;
	  cin>>n;
	  int arr[n+1];
	  for( int i=0;i<n;i++)
	        cin>>arr[i];
	    cout << calculate(arr, n)<<endl;
        
	}
	return 0;
}

// } Driver Code Ends


const int N = 1e5;

long long int calculate(int a[], int n)
{
    vector<long long> f(N+1, 0);
    for(int i=0; i<n; i++)
        f[a[i]]++;
     
    long long res = 0;   
    for(int i=0; i<=N; i++)
        res += f[i]*(f[i]-1)/2;
    
    return res;
}