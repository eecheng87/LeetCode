class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums.front();
        if (nums.size() == 2)
            return nums[1] > nums[0] ? nums[1] : nums[0];
        // if rob nums[0]
        int tmp = nums.back();
        nums.pop_back();
        int n1 = nums[1];
        nums[1] = INT_MIN;
        // if didn't rob nums[0]
        int a = reg_rob(nums);
        nums.push_back(tmp);
        nums[1] = n1;
        nums.erase(nums.begin());
        int b = reg_rob(nums);
        return a > b ? a : b;
    }
    int reg_rob(vector<int> &nums)
    {
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