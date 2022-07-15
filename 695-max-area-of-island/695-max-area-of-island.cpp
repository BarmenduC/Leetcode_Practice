class Solution {
public:
    void util(vector<vector<int>>& grid, int i, int j, int& curCount, int& maxCount) {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return;
        
        if(grid[i][j]==0) return;
        
        curCount++;
        
        grid[i][j]=0;
        
        util(grid, i-1, j, curCount, maxCount);
        util(grid, i+1, j, curCount, maxCount);
        util(grid, i, j-1, curCount, maxCount);
        util(grid, i, j+1, curCount, maxCount);
        
        maxCount=max(maxCount, curCount);
        
        return;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int maxArea=0, curCount=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
            curCount=0;
            if(grid[i][j]==1) util(grid, i, j, curCount, maxArea);
            }
        }
        return maxArea;
    }
};