class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		// First row:
        vector<vector<int>> pascal (1, vector<int>(1, 1));
        
        for (int i = 1; i < numRows; i++) {
			// Create a new row with the first value of 1:
            pascal.push_back(vector<int>(1, 1));
            for (int j = 0; j < pascal[i - 1].size() - 1; j++) {
				// Push each needed value into the new row, deriving them from values in the previous row:
                pascal[i].push_back(pascal[i - 1][j] + pascal[i - 1][j + 1]);
            }
			// Last value in the row is a 1:
            pascal[i].push_back(1);
        }
        
        return pascal;
    }
};