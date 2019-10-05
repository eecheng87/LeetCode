class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1, -1);
        if (n <= 2)
            return 1;
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 3; i <= n; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                dp[i] = max(max(j, dp[j]) * (i - j), dp[i]);
            }
        }
        return dp[n];
    }
};