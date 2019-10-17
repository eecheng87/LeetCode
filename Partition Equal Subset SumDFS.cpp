class Solution
{
public:
    bool dfs(vector<int> &nums, int first, int target, vector<int> &memo)
    {
        if (target < 0)
            return false;
        if (memo[target] > -1)
            return memo[target] == 1;
        for (int i = first; i < nums.size(); ++i)
        {
            if (dfs(nums, i + 1, target - nums[i], memo) || dfs(nums, i + 1, target, memo))
            // logic order is important! if switch will be wrong answer!!
            {
                memo[target] = 1;
                return true;
            }
        }
        memo[target] = 0;
        return false;
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;

        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];
        if (sum & 1 == 1)
            return false; // odd
        else
            sum /= 2;

        vector<int> memo(sum + 1, -1); // -1: doesn't visit
                                       //  0: false
                                       //  1: true
        memo[0] = 1;

        return dfs(nums, 0, sum, memo);
    }
};