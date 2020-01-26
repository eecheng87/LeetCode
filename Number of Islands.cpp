class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == '1' && find(grid, j, i) > 0)
                {
                    ans += 1;
                }
        return ans;
    }
    int find(vector<vector<char>> &grid, int x, int y)
    {
        if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size())
            return 0;
        if (grid[y][x] == '1')
        {
            grid[y][x] = '0';
            return 1 + find(grid, x - 1, y) + find(grid, x + 1, y) + find(grid, x, y - 1) + find(grid, x, y + 1);
        }
        return 0;
    }
};