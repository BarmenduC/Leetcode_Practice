class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> t(n,vector<int>(amount+1,-1));
        int res=fun(coins,n-1,amount,t);
        if(res>=1e9) 
            return -1;
        return res;
    }
    int fun(vector<int>& coins,int i,int amount,vector<vector<int>>& t)
    {
        if(i==0)
        {
            if(amount%coins[0]==0) 
                return amount/coins[0];
            else 
                return 1e9;
    }
        if(t[i][amount]!=-1)
            return t[i][amount];       
        int l=fun(coins,i-1,amount,t); 
        int w=1e9;
        if(coins[i]<=amount)
            w=1+fun(coins,i,amount-coins[i],t);
        return t[i][amount]=min(w,l);
    }
};