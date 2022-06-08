class Solution {
    bool checkPalin(string s){
        string p = s;
        reverse(p.begin(), p.end());
        return s==p;
    }
public:
    int removePalindromeSub(string s) {
        if(s.size()==0) return 0;
        if(checkPalin(s))   return 1;
        return 2;
    }
};