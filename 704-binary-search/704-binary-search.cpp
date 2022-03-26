class Solution {
public:
    int search(vector<int>& nums, int target) {
        // implementation of the binary search algorithm:
        // https://en.wikipedia.org/wiki/Binary_search_algorithm
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while (l <= r) {
            int m = (l+r)/2;
            if (nums[m] < target)
                l = m+1;
            else if (nums[m] > target)
                r = m-1;
            else
                return m;
        }
        return -1;
    }
};