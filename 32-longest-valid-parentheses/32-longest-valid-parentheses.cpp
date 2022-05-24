class Solution {
public:
    int longestValidParentheses(string s) {
        deque<pair<int,char>> st;
        int left = 0;
        if(s == "")
            return 0;
        while(left < s.size())
        {
            if(s[left] == ')')
                if(!st.empty() && st.back().second == '(')
                    st.pop_back();
                else
                    st.push_back({left,s[left]});
            else
                st.push_back({left,s[left]});
            left++;
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.front().first);
            st.pop_front();
        }
        int mx;
        if(ans.size() == 0)
            return s.size();
        else if(ans.size() == s.size())
            return 0;
        else
        {
            mx = ans[0];
            left = 0;
            int right = 1;
            int n = ans.size();
            while(right < n)
            {
                mx = max(mx,ans[right]-ans[left]-1);
                right++;
                left++;
            }
            if(ans[n-1] != s.size()-1)
            {
                int tmp = s.size()-1-(ans[n-1]);
                mx = max(mx,tmp);   
            }
        }
        return mx;
    }
};