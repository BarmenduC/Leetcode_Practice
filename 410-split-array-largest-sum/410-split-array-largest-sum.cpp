class Solution {    
public:
    
    bool f_chk(vector<int>& nums, int m, int sum) {
        int s = 0;
        for (int n : nums) {
            if (n > sum) {
                m = 0;
                break;
            }
            
            s += n;
            if (s > sum) {                
                s = n;
                m --;
            }
            if (m <= 0) break;
        }
        
        if(m > 0) return true;
        return false;
    }
    
    int f_search (int s, int e, vector<int>& nums, int m) {
        int v = 0;
        while (s < e) {
            v = (s+e) / 2;
            if (f_chk(nums, m, v) == false) s = v + 1;
            else e = v;
        }
        return s;
    }
    
    int splitArray(vector<int>& nums, int m) {
        return f_search(0, 1000000000, nums, m);
    }
};