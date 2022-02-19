class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> sec;
        sec.insert(nums.begin(), nums.end());
        int mini = *sec.rbegin() - *sec.begin();
		int val = *sec.begin();
        while (val % 2 == 1) {
            sec.erase(val);
            sec.insert(val * 2);
            val = *sec.begin();
            mini = min(mini, *sec.rbegin() - *sec.begin());
        }
        
        val = *sec.rbegin();
        while (val % 2 == 0) {
            sec.erase(val);
            sec.insert(val / 2);
            val = *sec.rbegin();   
            mini = min(mini, *sec.rbegin() - *sec.begin());
        }
        
        return mini;
    }
};