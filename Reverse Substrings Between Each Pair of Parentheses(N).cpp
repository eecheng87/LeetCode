class Solution
{
public:
    string reverseParentheses(string s)
    {
        vector<int> info, pair(s.size());
        string ans;

        // collect info about corresponding pair with '(' and ')'
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                info.push_back(i);
            }
            else if (s[i] == ')')
            {
                int k = info.back();
                info.pop_back();
                pair[i] = k;
                pair[k] = i;
            }
        }

        int index = 0;
        int dir = 1; // direction
        for (; index < s.size(); index += dir)
        {
            if (s[index] == '(' || s[index] == ')')
            {
                dir = -dir;
                index = pair[index];
            }
            else
            {
                ans += s[index];
            }
        }

        return ans;
    }
};