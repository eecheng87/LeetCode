class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // reverse up and down
        for(int i = 0; i < matrix.size()/2; ++i)
            for(int j = 0; j < matrix[i].size(); ++j){
                matrix[i][j] ^= matrix[matrix.size()-1-i][j];
                matrix[matrix.size()-1-i][j] ^= matrix[i][j];
                matrix[i][j] ^= matrix[matrix.size()-1-i][j];
            } 
        // swap symmetry
        for(int i = 0; i < matrix.size(); ++i)
            for(int j = i + 1; j < matrix[i].size(); ++j){
                matrix[i][j] ^= matrix[j][i];
                matrix[j][i] ^= matrix[i][j];
                matrix[i][j] ^= matrix[j][i];
            }
    }
};