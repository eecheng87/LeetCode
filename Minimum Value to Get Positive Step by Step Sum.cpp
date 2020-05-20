class Solution
{
public:
    int minStartValue(vector<int> &nums)
    {
        int low = 1;
        int s = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            s += nums[i];
            low = min(low, s);
        }
        return low == 1 ? low : abs(low) + 1;
    }
};