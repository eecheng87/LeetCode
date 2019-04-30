class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        int major;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
                major = nums[i];
            count += (major == nums[i]) ? 1 : -1;
        }
        return major;
    }
};