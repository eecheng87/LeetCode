class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        dfs(ans, 0, 0, s, "");
        return ans;
    }
    void dfs(vector<string> &ans, int i, int count, string s, string ele)
    {

        if (count == 4)
            if (i == s.size())
                ans.push_back(ele.substr(0, ele.size() - 1));
            else
                return;

        count++;
        for (int j = 1, k = 0; j < 4, k != 1; ++j)
        {
            if (s.size() < i + j)
                return;
            string tmp = s.substr(i, j); // j = 1~3
            if (stoi(tmp) > 255)
                return;
            if (stoi(tmp) == 0)
                k = 1;
            dfs(ans, i + j, count, s, ele + tmp + '.');
        }
    }
};