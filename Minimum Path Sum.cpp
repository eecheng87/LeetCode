class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int i, j;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 10000));

        for (i = 0; i < grid.size(); ++i)
        {
            for (j = 0; j < grid[0].size(); j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = grid[i][j];
                }
                else if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                }
                else if (i == 0)
                {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
                }
            }
        }

        return dp[grid.size() - 1][grid[0].size() - 1];
    }
    int min(int a, int b)
    {
        return a < b ? a : b;
    }
};