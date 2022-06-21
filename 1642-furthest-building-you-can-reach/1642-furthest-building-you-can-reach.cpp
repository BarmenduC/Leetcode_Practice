class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> strat;
        int max_pos = 0;
        int bricks_used = 0;
        for(int i=1; i< heights.size(); i++)
        {
            int jump_req = heights[i]-heights[i-1];            
            if(jump_req >0)
            {
                strat.push(heights[i]-heights[i-1]);
            }           
            if(strat.size()>ladders)
            {
                bricks_used += strat.top();
                strat.pop();
            }
            if(bricks_used > bricks)
            {
                return i-1;
            }
        }
        return heights.size()-1;
    }
};