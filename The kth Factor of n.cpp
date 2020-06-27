class Solution
{
public:
    int kthFactor(int n, int k)
    {
        vector<int> li;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
                li.push_back(i);
        }
        return k > li.size() ? -1 : li[k - 1];
    }
};