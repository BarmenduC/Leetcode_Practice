class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        int n = s.size();
		//marking the last occurence of the character s[i] 
        for(int i=0; i<n; i++)
        {
            m[s[i]] = i;
        }
        vector<int> ans;
        int last = 0;
        for(int i=0; i<n; i++)
        {
			//marking the last occurence of the whole substring till which we have traversed till now
            last = max(last, m[s[i]]);
			//if we are on the last occurence already 
            if(last == i)
            {
                ans.push_back(i);
                last = 0;
            }
        }
		//since the values are value of i and not lengths
        for(int i=ans.size()-1; i>=1; i--)
        {
            ans[i] = ans[i] - ans[i-1];
        }
		//since the loop are 0 based indexing 1st element is always 1 less therefore
        ans[0]++;
        return ans;
    }
};