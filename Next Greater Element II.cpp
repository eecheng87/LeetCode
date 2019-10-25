class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        vector<int> stack;
        for (int i = 0; i < n * 2; i++)
        {
            while (!stack.empty() && nums[stack.back()] < nums[i % n])
            {
                ans[stack.back()] = nums[i % n];
                stack.pop_back();
            }
            stack.push_back(i % n);
        }
        return ans;
    }
};