class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        if (s.size() <= 1)
            return;
        int n = s.size();
        int i = 0;
        int j = n - 1;
        char tmp;
        while (i < j)
        {
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++, j--;
        }
    }
};