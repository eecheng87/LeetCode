class Solution
{
public:
    string reformat(string s)
    {
        vector<char> dv, cv;
        int di = 0, ci = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] <= 'z' && s[i] >= 'a')
            {
                cv.push_back(s[i]);
            }
            else
            {
                dv.push_back(s[i]);
            }
        }
        int d = dv.size(), c = cv.size();
        if (abs(c - d) >= 2)
            return "";
        string ans = "";
        if (c > d)
        {
            ans += cv[ci++];
            while (c != ci)
            {
                ans += dv[di++];
                ans += cv[ci++];
            }
        }
        else if (c == d)
        {
            while (c != ci && d != di)
            {
                ans += cv[ci++];
                ans += dv[di++];
            }
        }
        else
        {
            ans += dv[di++];
            while (d != di)
            {
                ans += cv[ci++];
                ans += dv[di++];
            }
        }

        return ans;
    }
};