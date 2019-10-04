class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int a = 0, b = 0, i = 0;
        vector<int> dp(nums.size(), -1);
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0];
        else if (nums.size() == 2)
            return nums[0] > nums[1] ? nums[0] : nums[1];
        else if (nums.size() == 3)
            return nums[0] + nums[2] > nums[1] ? nums[0] + nums[2] : nums[1];
        dp[0] = nums[0];
        dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        dp[2] = nums[0] + nums[2] > nums[1] ? nums[0] + nums[2] : nums[1];
        int m = max(dp[2], dp[1]);
        for (int i = 3; i < nums.size(); ++i)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 3] + nums[i]);
            m = max(m, dp[i]);
        }

        return m;
    }
};