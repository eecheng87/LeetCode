class Solution
{
public:
    int sum(int n)
    {
        int ans = 0;
        while (n > 9)
        {
            ans += n % 10;
            n /= 10;
        }
        ans += n;
        return ans;
    }
    int countLargestGroup(int n)
    {
        int maxsize = -1, ans = 0;
        map<int, int> mp;
        for (int i = 1; i <= n; i++)
        {
            mp[sum(i)]++;
            maxsize = max(maxsize, mp[sum(i)]);
        }

        for (auto x : mp)
        {
            if (x.second == maxsize)
                ans++;
        }

        return ans;
    }
};