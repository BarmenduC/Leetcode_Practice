class Solution {
public:
    int chk[(1 << 20) + 1];
    bool hasAllCodes(string s, int k) {
        if(s.length() < k) return false;
        
        int cnt = 1 << k; // the count of all numbers in k length binary
        int cmp = (1<<k) - 1;  // 0000111...
        int val = 0; // number of k length bit from s
        
        // make k-1 length number in binary
        for (int i=0; i<k-1; i++) {
            val <<= 1;
            val += s[i] - '0';
        }
        
        // check val is existing in chk
        for (int i=k-1; i<s.length(); i++) {
            val <<= 1;
            val |= s[i] - '0';
            val = (val & cmp); // make k length binary number
            if(chk[val] == 0){
                cnt--;
                chk[val] = 1;
            }
            if (cnt == 0) return true; // If found all
        }
        
        return false;
    }
};