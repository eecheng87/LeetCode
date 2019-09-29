class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        bool flag = false;
        bool same = true;
        int i, j, m;
        while (1)
        {
            for (i = 0; s.size() >= k && i <= s.size() - k; i++)
            {
                for (j = 0; j < k; j++)
                {
                    if (s[i + j] != s[i])
                    {
                        same = false;
                        j = k;
                    }
                }

                if (same)
                {
                    s = s.substr(0, i) + s.substr(i + k);
                    flag = true;
                    i--;
                }
                else
                {
                    same = true;
                }
            }

            if (flag && s.size() >= k)
            {
                flag = false;
            }
            else
            {
                break;
            }
        }
        return s;
    }
};