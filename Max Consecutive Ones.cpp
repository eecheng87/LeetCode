class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ans = nums[0], tmp = nums[0], pre = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                tmp = (pre == 1) ? tmp + 1 : 1;
            }
            else
            {
                tmp = 0;
            }
            pre = nums[i];
            ans = max(ans, tmp);
        }
        return ans;
    }
};