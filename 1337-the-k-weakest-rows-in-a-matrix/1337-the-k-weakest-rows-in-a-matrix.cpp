class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> row_counts(mat.size(), vector<int>(2, 0));
        for(int i = 0; i < mat.size(); i++){
            row_counts[i][0] = i;
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 1)
                    row_counts[i][1]++;
                else break;
            }
        }
        sort(row_counts.begin(), row_counts.end(), rowComparator);
        vector<int> sol(k, 0);
        for(int i = 0; i < k; i++){
            sol[i] = row_counts[i][0];
        }
        return sol;
    }

private:
    static bool rowComparator(vector<int>& a, vector<int>& b){
        if(a[1] == b[1]) return (a[0] < b[0]);
        else return a[1] < b[1];
    }
};