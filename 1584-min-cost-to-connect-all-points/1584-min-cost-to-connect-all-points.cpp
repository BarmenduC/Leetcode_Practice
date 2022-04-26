class Solution {
public:
    typedef pair<int, pair<int, int>> three;
    
    // find the root of disjointed set
    int find(vector<int>& parent, int x){
        if(parent[x] < 0)
            return x;
        
        return parent[x] = find(parent, parent[x]);
    }
    
    // union the disjointed set
    void make_union(vector<int>& parent, int root1, int root2){
        if(root1==root2)
            return;
        if(parent[root1] < parent[root2])
        {
            parent[root1] += parent[root2];
            parent[root2] = root1;
        }
        else
        {
            parent[root2] += parent[root1];
            parent[root1] = root2;
        }
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        // looks like pairing worker with bikes problem
        // using priority queue to store all possible distance
        // using disjointed set to make all points connected
        vector<int> parent(points.size(), -1);
        
        priority_queue<three, vector<three>, greater<three>> que;
        
        int res = 0;
        for(int i = 0; i < points.size(); ++i){
            for(int j = 0; j <i; ++j){
                que.push(make_pair(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), make_pair(i, j)));
            }
        }
        
        while(!que.empty()){
            auto cur = que.top();
            que.pop();
            if(find(parent, cur.second.first) != find(parent, cur.second.second)){
                res += cur.first;
                make_union(parent, find(parent, cur.second.first), find(parent, cur.second.second));
            }
        }
        return res;
    }
};