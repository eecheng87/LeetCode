class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<string> cpy(strs); // copy vector
        vector<vector<string>> ans;
        vector<string> tmp;
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < cpy.size(); ++i)
        {
            sort(cpy[i].begin(), cpy[i].end());
            mp[cpy[i]].push_back(i);
        }
        for (unordered_map<string, vector<int>>::iterator it = mp.begin(); it != mp.end(); ++it)
        {
            tmp.clear();
            if (it->second.size() > 0)
            {
                for (int j = 0; j < it->second.size(); ++j)
                {
                    tmp.push_back(strs[it->second[j]]);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};