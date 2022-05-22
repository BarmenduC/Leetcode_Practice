class Solution {
public:
    int countSubstrings(string s) {
        int l,r;
        int z=0;
        
        for(int i=0;i<s.size();i++){
            l=i,r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                z++;
                l--;r++;
            }
            
            l=i,r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                z++;
                l--;r++;
            }
        }
        
        return z;
    }
};