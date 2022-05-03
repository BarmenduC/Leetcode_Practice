// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> permute(vector<vector<int>> &arr, int n);


int main() {
    
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> arr(n);
        
        for(int i=0;i<n;i++)
        {
            int a, b;
            cin>> a>> b;
            arr[i].push_back(a);
            arr[i].push_back(b);
        }
        
        vector<int> ans;
        ans = permute(arr, n);
        for(int i=0;i<n;i++)
            cout << ans[i] << "\n";
        
    }
    
	return 0;
}// } Driver Code Ends


vector<int> permute(vector<vector<int>> &arr, int n)
{
    
    vector<int>ans;
    map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        mp[arr[i][0]+arr[i][1]].push_back(i+1);
        sort( mp[arr[i][0]+arr[i][1]].begin(), mp[arr[i][0]+arr[i][1]].end());
    }
    map<int,vector<int>>::iterator it;
    it=mp.begin();
    for(;it!=mp.end();it++){
        int l=(it->second).size();
        
        for(int i=0;i<l;i++){
           ans.push_back((it->second)[i]);}
    }
    return ans;
    
}