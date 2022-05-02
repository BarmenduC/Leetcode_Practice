class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] % 2) {
                swap(nums[r--], nums[l]);
            } else {
                ++l;
            }
        }
        return nums;
    }
};