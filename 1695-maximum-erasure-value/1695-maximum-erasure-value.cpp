class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int l = 0;
        int r = 0;
		int best = 0;
        int score = 0;
        vector<int> vals(10001, 0);
		
        while(r < nums.size()){
            if(vals[nums[r]] == 0){
                vals[nums[r]]++;
                score += nums[r];
                best = max(best, score);
                r++;
            }
            else{
                score -= nums[l];
                vals[nums[l]]--;
                l++;
            }
        }
        return best;
    }
};