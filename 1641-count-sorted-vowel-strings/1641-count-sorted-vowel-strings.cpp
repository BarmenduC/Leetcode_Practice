class Solution {
public:
    
    int Choose4(int n)
    {
        long int ret;
        ret=n*(n-1)*(n-2)*(n-3);
        ret=ret/24;
        
        return(ret);
    }
    
    
    int countVowelStrings(int n) {
        
        return(Choose4(n+4));
        
    }
};