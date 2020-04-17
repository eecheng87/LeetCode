class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        int ans = -1;
        map<int, int> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            if (it->first == it->second)
            {
                ans = max(ans, it->first);
            }
        }
        return ans;
    }
};