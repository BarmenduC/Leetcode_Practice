class Solution {
public:
   vector<vector<int>> res;
    void solve(int i,int sum,int k,vector<int> ans,vector<int> a)
    {
        if(i==a.size())
        {
            if(ans.size()==k && sum==0)
                res.push_back(ans);
            return;
        }
        else
        {
            if(ans.size()<k)
            {
                if(a[i]<=sum)
                {
                    solve(i+1,sum,k,ans,a);
                    ans.push_back(a[i]);
                    sum=sum-a[i];
                    solve(i+1,sum,k,ans,a);
                    ans.pop_back();
                }
                else
                    solve(i+1,sum,k,ans,a);
            }
            else
                solve(i+1,sum,k,ans,a);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k>n)
            return {};
        vector<int> temp;
        for(int i=1;i<=9;i++)
            temp.push_back(i);
        vector<int> ans;
        solve(0,n,k,ans,temp);
        return res;
    }
};