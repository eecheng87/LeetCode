class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int m = -1;
        for (auto i : candies)
            m = max(m, i);
        vector<bool> ans(candies.size(), false);
        for (int i = 0; i < ans.size(); i++)
        {
            if (candies[i] + extraCandies >= m)
                ans[i] = true;
        }
        return ans;
    }
};