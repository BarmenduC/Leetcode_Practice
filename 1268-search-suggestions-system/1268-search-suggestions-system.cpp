class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& a, string w) {
        int n=w.size();
        vector<vector<string>>res(n);
        sort(a.begin(),a.end());
        int m=a.size();
        for(int i=0;i<m;i++){
            if(a[i][0]==w[0])
                res[0].push_back(a[i]);
        }
        for(int i=1;i<n;i++){
            for(auto x:res[i-1]){
                if(x.size()<=i)
                    continue;
                if(x[i]==w[i])
                    res[i].push_back(x);
            }
        }
        for(int i=0;i<n;i++){
            if(res[i].size()>3)
            res[i].resize(3);
        }
        return res;
    }
};