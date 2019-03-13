class Solution
{
  public:
    bool containsDuplicate(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return false;
        }
        sort(nums.begin(), nums.end());
        int prev;
        prev = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                return true;
            }
            else
            {
                prev = nums[i];
            }
        }
        return false;
    }
};