class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if (target <=  startValue) return startValue - target; 
        // Else 
        if (target % 2 == 1) return brokenCalc (startValue, target + 1) + 1;  
        return brokenCalc (startValue, target / 2) + 1; 
        
    }
};