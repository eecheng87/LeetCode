class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = piles[i];
        for (int interval = 1; interval < n; ++interval)
            for (int j = 0; j < n - interval; j++)
            {
                dp[j][j + interval] = max(piles[j] - dp[j + 1][j + interval], piles[j + interval] - dp[j][j + interval - 1]);
            }
        return dp[0][n - 1] > 0;
    }
};