class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, 10000);
        if (amount == 0)
            return 0;
        for (auto i : coins)
            if (i < amount)
                dp[i] = 1;
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); ++j)
            {
                int t = coins[j];
                if (i >= t)
                    dp[i] = min(dp[i - t] + 1, dp[i]);
            }
        }
        return dp[amount] > 9999 ? -1 : dp[amount];
    }
};