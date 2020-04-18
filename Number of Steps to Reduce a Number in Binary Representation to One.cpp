class Solution
{
public:
    int numSteps(string s)
    {
        int ans = 0;
        while (s.size() > 1)
        {
            if (s[s.size() - 1] == '0')
            {
                s.pop_back();
            }
            else
            {
                int index = s.size() - 1;
                s[index] = '0';
                index--;
                while (index >= 0 && s[index] == '1')
                {
                    s[index] = '0';
                    index--;
                }
                if (index < 0)
                {
                    s = "1" + s;
                }
                else
                {
                    s[index] = '1';
                }
            }
            cout << s << endl;
            ans++;
        }
        // if(s[0] == '1')
        return ans;
    }
};