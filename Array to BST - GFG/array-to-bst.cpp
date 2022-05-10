// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    void convertToBST(vector<int> &nums, int start, int end, vector<int> &preorder)
    {
        if(start > end) return;
        int mid = (start + end) >> 1;
        preorder.push_back(nums[mid]);
        convertToBST(nums, start, mid-1, preorder);
        convertToBST(nums, mid+1, end, preorder);
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int> preorder;
        convertToBST(nums, 0, nums.size()-1, preorder);
        return preorder;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends