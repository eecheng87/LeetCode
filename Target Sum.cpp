class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int sum = 0;
        for (auto i : nums)
            sum += i;
        if (S > sum || -sum > S)
            return 0;
        int dp[nums.size() + 1][2 * sum + 1];
        memset(dp, 0, sizeof dp);
        dp[0][sum] = 1;
        for (int i = 1; i < nums.size() + 1; i++)
        {
            for (int j = 0; j <= 2 * sum; j++)
            {
                if (nums[i - 1] + j <= 2 * sum)
                    dp[i][j] += dp[i - 1][nums[i - 1] + j];
                if (j - nums[i - 1] >= 0)
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[nums.size()][S + sum];
    }
};
