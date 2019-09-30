class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";
        if (s.size() == 1)
            return s;
        int n = 0;
        int j, k, i, num;
        string ans;
        string tmp;
        for (; n < s.size() - 1;)
        {
            if (s.size() - n < tmp.size() / 2)
                break; // this line is important for performance
            i = 1;
            while (s[n] == s[n + i])
                i++;
            ans = s.substr(n, i);
            k = n + i;
            j = n - 1;
            while (j >= 0 && k < s.size())
            {
                if (s[j] != s[k])
                    break;
                --j;
                ++k;
            }
            ans = s.substr(j + 1, k - j - 1);
            n += i;
            tmp = tmp.size() > ans.size() ? tmp : ans;
        }
        tmp = tmp.size() > ans.size() ? tmp : ans;
        if (tmp.empty())
            return s.substr(0, 1);
        return tmp;
    }
};