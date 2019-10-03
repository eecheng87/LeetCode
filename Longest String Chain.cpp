class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), cmp);
        unordered_map<string, int> dp;

        int ans = 0;
        int best = 0;
        for (auto w : words)
        {
            best = 0;
            for (int i = 0; i < w.size(); ++i)
            {
                string tmp = w.substr(0, i) + w.substr(i + 1);
                best = max(dp[tmp] + 1, best);
            }
            dp[w] = best;
            ans = max(ans, best);
        }

        return ans;
    }
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    static bool cmp(const string a, const string b)
    {
        return a.size() < b.size();
    }
};