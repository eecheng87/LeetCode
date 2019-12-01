class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        vector<int> countr(grid.size(), 0);
        vector<int> countc(grid[0].size(), 0);
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                countr[i] += grid[i][j];
                countc[j] += grid[i][j];
            }
        }

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if ((countr[i] > 1 || countc[j] > 1) && grid[i][j] == 1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};