class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        int ans = -100;
        unordered_map<int, int> map;

        for (int i = arr.size() - 1; i >= 0; --i)
        {
            map[arr[i]] = map[arr[i] + difference] + 1;
            ans = max(ans, map[arr[i]]);
        }
        return ans;
    }
};