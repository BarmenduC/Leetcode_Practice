class Solution {
public:
    static bool sortByVal(pair<int, int> &a, pair<int, int> &b) { 
        return (a.second > b.second); 
    } 
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>m;
        for(int i=0;i<nums.size();i++) {
            m[nums[i]]++;
        }
        vector<int>res;
        vector<pair<int, int>>v;
        for(auto i:m){
            v.push_back(make_pair(i.first, i.second));
        }
        sort(v.begin(), v.end(), sortByVal);
        for(auto i:v) {
            if(k) {
                res.push_back(i.first);
                k--;
            }
        }
        return res;
    }
};