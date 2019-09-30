class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {

        if (wordDict.size() == 0)
            return false;

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true; // dummy variable
        for (int i = 1; i < s.size() + 1; ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (dp[j])
                {
                    string tmp = s.substr(j, i - j);
                    if (find(tmp, wordDict))
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
    bool find(string tmp, vector<string> dict)
    {
        bool ans = false;
        for (auto i : dict)
        {
            if (i == tmp)
            {
                ans = true;
                break;
            }
        }
        return ans;
    }
};