class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &t)
    {
        vector<int> stack;
        vector<int> ans(t.size(), 0);
        int n;
        for (int i = 0; i < t.size(); ++i)
        {
            while (!stack.empty() && t[stack.back()] < t[i])
            {
                ans[stack.back()] = i - stack.back();
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return ans;
    }
};