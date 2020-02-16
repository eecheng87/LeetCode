class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size() - 1;
        int col = grid[0].size() - 1;
        int ans = 0;
        for(int i = 0; i <= row; i++)
            for(int j = 0; j <= col; j++){
                // grid[i][j]
                if(grid[i][j] < 0){
                    ans += grid[0].size() - j;
                    col = j;
                }
            }
        
        return ans;
    }
};