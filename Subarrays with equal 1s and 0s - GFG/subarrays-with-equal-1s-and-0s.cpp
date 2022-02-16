// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
         map<int,int>s;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0) arr[i]=-1;
        }
 /*For all subarray You have to sum the frequecies of the repeating sum then increase the repeating frequencies*/
 
        int all_sub_array=0;
        int sum=0;
        s[sum]++;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(s.find(sum)!=s.end())
            {
                all_sub_array+=(s.find(sum)->second);
                s[sum]++;
            }
            else s[sum]++;
        }
        return all_sub_array;
     }
    
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends