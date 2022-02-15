class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i=0, res=0;
        for(i;i<nums.size();i++)
            res^=nums[i];
        return res;
    }
};