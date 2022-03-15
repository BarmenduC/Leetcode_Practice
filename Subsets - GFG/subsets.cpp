// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    static bool comp(vector<int> &v1, vector<int> &v2) {
        int n1=v1.size(), n2=v2.size();
        for(int i=0; i<min(n1,n2); ++i) {
            if(v1[i]!=v2[i]) return v1[i]<v2[i];
        }
        return n1<=n2;
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        vector<vector<int>> ans;
        int n=A.size();
        for(int i=0; i<(1LL<<n); ++i) {
            vector<int> temp;
            for(int j=0; j<n; ++j) {
                if(i&(1LL<<j)) {
                    temp.push_back(A[j]);
                }
            }
            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end(),comp);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends