class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<vector<char>> subs;
        for(int i = 0; i < s.size(); i++){
            if(subs.size() > 0 && subs[subs.size()-1][0] == s[i]){
                subs[subs.size()-1].push_back(s[i]);
                if(subs[subs.size()-1].size() == k)
                    subs.pop_back();
            }
            else(subs.push_back({s[i]}));
        }
        string ans = "";
        for(int i = 0; i < subs.size(); i++)
            for(int j = 0; j < subs[i].size(); j++)
                ans.push_back(subs[i][j]);
        return ans;
    }
};