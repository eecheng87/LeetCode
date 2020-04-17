class Solution
{
public:
    int nChoosek(int n, int k)
    {
        if (k > n)
            return 0;
        if (k * 2 > n)
            k = n - k;
        if (k == 0)
            return 1;

        int result = n;
        for (int i = 2; i <= k; ++i)
        {
            result *= (n - i + 1);
            result /= i;
        }
        return result;
    }
    int numTeams(vector<int> &rating)
    {
        int ans = 0;
        for (int i = 0; i < rating.size() - 2; i++)
        {
            for (int j = i + 1; j < rating.size() - 1; j++)
            {
                for (int k = j + 1; k < rating.size(); k++)
                {
                    if (rating[i] < rating[j] && rating[j] < rating[k])
                        ans++;
                    if (rating[i] > rating[j] && rating[j] > rating[k])
                        ans++;
                }
            }
        }
        return ans;
    }
};