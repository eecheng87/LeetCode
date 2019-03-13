class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        ans.push_back(tmp);
        for (int i = 0; i < nums.size(); i++)
        { // for nums
            int n = ans.size();
            for (int j = 0; j < n; j++)
            {
                ans.push_back(ans[j]);
                ans[ans.size() - 1].push_back(nums[i]); // last element
            }
        }
        return ans;
    }
};