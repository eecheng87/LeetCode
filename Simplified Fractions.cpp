class Solution
{
public:
    int get_gcd(int a, int b)
    {
        int gcd = 1;
        for (int i = 2; i <= a && i <= b; ++i)
        {
            if (a % i == 0 && b % i == 0)
                gcd = i;
        }
        return gcd;
    }
    vector<string> simplifiedFractions(int n)
    {
        vector<string> ans;
        if (n == 1)
            return ans;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (get_gcd(i, j) == 1 || j == 1)
                {
                    ans.push_back(to_string(j) + "/" + to_string(i));
                }
            }
        }

        return ans;
    }
};