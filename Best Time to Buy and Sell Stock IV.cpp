class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (k > prices.size() / 2)
        {
            int ans = 0;
            for (int i = 1; i < prices.size(); ++i)
                ans += max(prices[i] - prices[i - 1], 0);
            return ans;
        }
        vector<vector<int>> dp(k + 1, vector<int>(prices.size(), 0));
        int tmp;

        for (int i = 0; i <= k; ++i)
            dp[i][0] = 0;
        for (int j = 0; j < prices.size(); ++j)
            dp[0][j] = 0;
        for (int i = 1; i <= k; ++i)
        {
            tmp = -prices[0];
            for (int j = 1; j < prices.size(); ++j)
            {
                dp[i][j] = max(dp[i][j - 1], prices[j] + tmp);
                tmp = max(tmp, dp[i - 1][j - 1] - prices[j]);
            }
        }
        return dp[k][prices.size() - 1];
    }
};