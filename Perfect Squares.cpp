class Solution
{
public:
    int numSquares(int n)
    {
        if (n <= 0)
            return 0;
        vector<int> dp;
        dp.push_back(0);
        while (dp.size() <= n)
        {
            int m = dp.size();
            int tmp_ans = INT_MAX;
            for (int i = 1; i * i <= m; ++i)
            {
                tmp_ans = min(tmp_ans, dp[m - i * i] + 1);
            }
            dp.push_back(tmp_ans);
        }
        return dp[n];
    }
    bool sqrtable(int n)
    {
        if (sqrt(n) == (int)sqrt(n))
            return true;
        return false;
    }
};