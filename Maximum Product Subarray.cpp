class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int rmax = nums[0];
        int rmin = nums[0];
        int rmaxt, rmint;
        int ans = nums[0];
        if (nums.size() == 1)
            return nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
            {
                rmax = max(rmax * nums[i], nums[i]);
                rmin = min(rmin * nums[i], nums[i]);
            }
            else
            {
                rmaxt = max(rmin * nums[i], nums[i]);
                rmint = min(rmax * nums[i], nums[i]);
                rmax = rmaxt;
                rmin = rmint;
            }
            ans = ans > rmax ? ans : rmax;
        }
        return ans;
    }
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int min(int a, int b)
    {
        return a > b ? b : a;
    }
};