class Solution
{
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {

            int three_sum = target - nums[i];

            for (int j = i + 1; j < nums.size(); j++)
            {

                int two_sum = three_sum - nums[j];
                int front = j + 1;
                int last = nums.size() - 1;
                while (front < last)
                {
                    int sum = nums[front] + nums[last];
                    if (two_sum < sum)
                    {
                        last--;
                    }
                    else if (two_sum > sum)
                    {
                        front++;
                    }
                    else
                    {
                        vector<int> ans(4, 0);
                        ans[0] = nums[i];
                        ans[1] = nums[j];
                        ans[2] = nums[front];
                        ans[3] = nums[last];
                        res.push_back(ans);

                        while (front < last && nums[front] == ans[2])
                            front++;
                        while (front < last && nums[last] == ans[3])
                            last--;
                    }
                }
                while (j < nums.size() - 1 && nums[j] == nums[j + 1])
                    j++;
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                i++;
        }
        return res;
    }
};