class Solution {
public:
   vector < vector <int> > ans;
    
    void subsetsHelper(vector <int> &nums, vector <int> dummy, int i) {
        
        if(i == nums.size())
        {
            ans.push_back(dummy);
            return;
        }
        
		// pick ith element
        dummy.push_back(nums[i]);
        subsetsHelper(nums, dummy, i + 1);
		// remove ith element
        dummy.pop_back();
        subsetsHelper(nums, dummy, i + 1);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> dummy;
       subsetsHelper(nums, dummy, 0) ;
        return ans;
    }
};