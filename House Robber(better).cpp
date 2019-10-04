class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> mem(nums.size(), -1);
        vector<int> dp(nums.size());
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums.front();
        dp[0] = nums.front();
        dp[1] = nums.front() > nums[1] ? nums.front() : nums[1];
        for (int i = 2; i < nums.size(); ++i)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp.back();
    }
};