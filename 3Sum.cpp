class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end()); //nOlog(n)

        for (int i = 0; i < nums.size(); i++)
        {

            int front = i + 1;
            int last = nums.size() - 1;
            int target = -nums[i];

            while (last > front)
            {
                int sum = nums[front] + nums[last];
                if (target == sum)
                {
                    vector<int> ans(3, 0);
                    ans[0] = nums[i];
                    ans[1] = nums[front];
                    ans[2] = nums[last];
                    res.push_back(ans);
                    while (front < last && ans[1] == nums[front])
                        front++;
                    while (front < last && ans[2] == nums[last])
                        last--;
                }
                else if (target > sum)
                {
                    front++;
                }
                else
                {
                    last--;
                }
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }

        return res;
    }
};