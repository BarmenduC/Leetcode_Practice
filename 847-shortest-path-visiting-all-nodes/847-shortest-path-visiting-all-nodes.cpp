class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
       if(graph.size() == 0 || graph[0].size() == 0)
           return 0;
        map <int, vector <int> > mp;
        
        for(int i = 0 ; i < graph.size() ; i ++) {
        
                mp[i] = graph[i];
           
        }
        
        int ans = pow(2, graph.size()) -1;
        int r = graph.size();
        int c = ans;
        vector < vector <int> > dp(r, vector <int> (ans));
        
        
        queue < vector <int> >q;
        for(int i = 0 ; i < r ; i++) {
            
            dp[i][(1 << i)] = 1;
            q.push({i, (1 << i), 0});
        }
        
        
    
        while(!q.empty()) {
            vector <int> x  = q.front();
            q.pop();
            
            dp[x[0]][x[1]] = 1;
            if(x[1] == ans)
                return x[2];
            int n = x[0];
            vector <int> nodes = mp[n];
            for(int i = 0 ;  i < nodes.size() ; i++)
            {
                int l = nodes[i];
                int m = (x[1]) |(1 << l);
                if(m == ans)
                    return x[2] + 1;
                if(dp[l][m] == 1) {
                    continue;
                }
                
                dp[l][m] = 1;
                // cout << x[2]  << endl;
                q.push({l, m, x[2] + 1});
            }
            
            
        }
        return -1;
    }
};