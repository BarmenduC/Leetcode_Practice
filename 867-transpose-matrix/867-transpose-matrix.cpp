class Solution {
public:
     std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {
        int row  = matrix.size();
        int col  = matrix[0].size(); //row * col
        std::vector<std::vector<int>> solution(col , std::vector<int>(row,0)); // creation of col * row matrix
        for(int i =  0 ; i < row ; i++){
            for(int j = 0; j < col ; j++){
                solution[j][i] = matrix[i][j];// transpose filling
            }
        }
        return solution;
    }
};