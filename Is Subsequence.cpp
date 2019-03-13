class Solution
{
  public:
    bool isSubsequence(string s, string t)
    {
        int sIndex = 0;
        int tIndex = 0;
        while (sIndex < s.length() && tIndex < t.length())
        {
            if (s[sIndex] == t[tIndex])
            {
                sIndex++;
                tIndex++;
            }
            else
            {
                tIndex++;
            }
        }

        if (tIndex >= t.length() && sIndex < s.length())
        {
            return false;
        }
        else if (sIndex >= s.length() && tIndex >= t.length())
        {
            if (s[sIndex - 1] == t[tIndex - 1])
                return true;
            else
                return false;
        }
        else
        {
            return true;
        }
    }
};