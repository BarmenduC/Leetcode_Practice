// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 



 // } Driver Code Ends


class Solution{
 public:
   vector<int> maxProductSubsequence(int *arr , int n) 
   { 
       set<long int>st;
       long int res = -1;
       long int curr;
       vector<int>rmax(n);
       vector<int>ans;
       rmax[n-1] = arr[n-1];
       long int ele;
       for(int i = n-2; i >= 0; i--) {
           rmax[i] = max(rmax[i+1], arr[i]);
       }
       st.insert(arr[0]);
       for(int i = 1; i < n; i++) {
           st.insert(arr[i]);
           auto it = st.find(arr[i]);
           if(it != st.begin()) {
               it--;
               ele = *it;
               if(arr[i] < rmax[i]) {
                   curr = (long)arr[i]*rmax[i]*ele;
                   if(curr > res) {
                       ans = {ele, arr[i], rmax[i]};
                       res = curr;
                   }
               }
           }
       }
       if(ans.size() == 0) {
           return {-1};
       }
       return ans;
   }

};
// { Driver Code Starts.
// Driver Program 
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i = 0; i<num; ++i)
	        cin>>arr[i];
	    
	    vector<int> res;
	    Solution obj;
	    res = obj.maxProductSubsequence(arr, num);
	    
	    if(res[0] == -1)
	        cout<<"Not Present\n";
	    else{
    	    for(int i = 0; i<3; ++i)
    	        cout<<res[i]<<" ";
    	    cout<<"\n";
	    }
	    
	}
} 
  // } Driver Code Ends