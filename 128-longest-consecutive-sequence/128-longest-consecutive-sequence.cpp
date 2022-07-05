class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, bool> mp;
        int maxLen = 0, currLen = 0;

        for(int i = 0; i < n; i++) {
            mp[arr[i]] = true;
        }

        for(int i = 0; i < n; i++) {
            if(mp[arr[i]] == true) {
                int num = arr[i];
                while (mp.find(num) != mp.end()) {
                    mp[num] = false;
                    currLen += 1;
                    num += 1;
                }
                num = arr[i] - 1;
                while (mp.find(num) != mp.end()) {
                    mp[num] = false;
                    currLen += 1;
                    num -= 1;
                }
                maxLen = max(maxLen, currLen);
                currLen = 0;
            }
        }
        return maxLen;
    }
};