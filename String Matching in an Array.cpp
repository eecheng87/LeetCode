class Solution
{
public:
    static bool cmp(string a, string b)
    {
        return a.size() > b.size();
    }
    vector<string> stringMatching(vector<string> &words)
    {
        set<string> ans;

        sort(words.begin(), words.end(), cmp);
        for (int i = 0; i < words.size(); i++)
        {
            int j = words.size() - 1;
            while (i < j)
            {
                if (words[i].find(words[j]) != string::npos)
                {
                    ans.insert(words[j]);
                }
                j--;
            }
        }
        vector<string> vans(ans.size());
        int index = 0;
        for (auto i : ans)
        {
            vans[index++] = i;
        }
        return vans;
    }
};