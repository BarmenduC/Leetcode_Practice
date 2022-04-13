class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      bool row_col = true;
      int d = 1;
      int maxR = n - 1, minR = 0, maxC = n-1, minC = 0;
      int cnt = 0, i = 0, j = 0;
      vector<vector<int>> res(n, vector<int>(n));
      while (cnt < n*n) {
        res[i][j] = ++cnt;
        if (row_col) {
          if (j == maxC && d > 0) { // top right
            row_col = !row_col;
            i += d;
            minR++;
          } else if (j == minC && d < 0) { // bottom left
            row_col = !row_col;
            i += d;
            maxR--;
          } else {
            j += d;
          }
        } else {
          if (i == maxR && d > 0) { // bottom right
            row_col = !row_col;
            d = -1;
            maxC--;
            j += d;
          } else if (i == minR && d < 0) { // top left
            row_col = !row_col;
            d = 1;
            minC++;
            j += d;
          } else {
            i += d;
          }
        }
      }
      return res;
    }
};