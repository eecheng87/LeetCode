class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        vector<bool> arr(nums.size() + 1, false);
        for (auto i : nums)
        {
            arr[i] = true;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            if (!arr[i])
                return i;
        }
        return -1;
    }
};