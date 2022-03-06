class Solution {
public:
    long memo[501][501];
    int mod = 1e9 + 7;
    long dfs(int pickup, int deliver) {
        if (pickup == 0 && deliver == 0)
            return 1;

        if (pickup > deliver || pickup < 0 || deliver < 0)
            return 0;

        if (memo[pickup][deliver])
            return memo[pickup][deliver];

        // there are two options either to pickup or deliver
        long res = (deliver - pickup) * dfs(pickup, deliver - 1) + pickup * dfs(pickup - 1, deliver);
        return memo[pickup][deliver] = res % mod;
    }

    int countOrders(int n) {
        return dfs(n, n);
    }
};