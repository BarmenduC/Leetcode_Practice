class Solution {
public:    
    int f_max(int a, int b) {
        return (a > b)? a : b;
    }
    
    int lengthOfLongestSubstring(string s) {        
        if(s.length() == 0) return 0; // s is null
        
        int count[256] = {0}; // ascii code array
        int left = 0; // left index
        int right = 0; // right index
        int end = s.length()-1; // last index of string s
        int ans = 1; // answer
        ++count[s[left]]; // count up on first index
        
        // repeat while right < end
        while (right < end) {
            // if current range is vaild
            if(count[s[right]] == 1) {
                ans = f_max(ans, right-left+1); // update answer                
                ++right; // increase right index
                ++count[s[right]]; // count up for new right index ascii code
            }
            // if current range is unvaild
            else {
                --count[s[left]]; // count down for current left index ascii code
                ++left; // increase left index
            }
        }
        
        // process last posion
        if(count[s[right]] == 1) ans = f_max(ans, right-left+1);
        // return answer
        return ans;
    }
};