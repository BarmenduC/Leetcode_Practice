class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int med = nums[nums.size() / 2], minMovesCount = 0;
        for (int n : nums){
            minMovesCount += abs(n - med);
        }
        return minMovesCount;
    }
};