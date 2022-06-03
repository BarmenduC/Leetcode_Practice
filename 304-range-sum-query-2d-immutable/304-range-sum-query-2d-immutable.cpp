class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m.resize(matrix.size());
        for(int i = 0; i < m.size(); i++){
            m[i].resize(matrix[0].size());
            for(int j = 0; j < matrix[0].size(); j++){
                m[i][j] = matrix[i][j];
                if(j > 0) m[i][j] += m[i][j-1];
                }
        }
        return;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++){
            sum += m[i][col2];
            if(col1 > 0) sum -= m[i][col1-1];
        }
        return sum;
    }
private:
    vector<vector<int>> m;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */