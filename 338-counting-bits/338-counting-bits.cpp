class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> vec(n+1, 0);
        for(int i = 1; i <= n; i++){
            vec[i] = vec[(i&(i-1))] + 1;
        }
        return vec;
    }
};