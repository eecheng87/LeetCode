class Solution
{
public:
    unordered_map<int, int> mp;
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        return dfs(price, special, needs);
    }
    int dfs(vector<int> price, vector<vector<int>> special, vector<int> needs)
    {
        int subans = prod(price, needs);
        int i, j, tmp;
        if (mp.count(hash(needs)))
            return mp[hash(needs)];
        vector<int> newneed(needs.size(), 0);
        for (i = 0; i < special.size(); ++i)
        {
            for (j = 0; j < needs.size(); ++j)
            {
                if (needs[j] - special[i][j] < 0)
                    break;
                else
                    newneed[j] = needs[j] - special[i][j];
            }
            if (j == needs.size())
            {
                subans = min(subans, special[i].back() + dfs(price, special, newneed));
            }
        }
        mp[hash(needs)] = subans;
        return subans;
    }
    int prod(vector<int> price, vector<int> needs)
    {
        int tmp = 0;
        for (int i = 0; i < price.size(); ++i)
            tmp += price[i] * needs[i];
        return tmp;
    }
    int hash(vector<int> need)
    {
        int ans = 0;
        for (int i = 0; i < need.size(); ++i)
            ans = ans * 10 + need[i];
        return ans;
    }
};