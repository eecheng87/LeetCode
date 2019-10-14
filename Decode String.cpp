class Solution
{
public:
    string decodeString(string s)
    {
        //return "";
        vector<int> istack;
        vector<string> sstack;

        string tmp;
        for (int i = 0; i < s.length(); ++i)
        {
            //cout<<"A";
            if (s[i] < 60)
            {
                // digit
                int digit = 0;
                while (s[i] < 60)
                {
                    digit = digit * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                istack.push_back(digit);
            }
            else if (s[i] == ']')
            {
                string tok = sstack.back();
                sstack.pop_back();
                tok += repeat(tmp, istack.back());
                tmp = tok;
                istack.pop_back();
            }
            else if (s[i] == '[')
            {
                sstack.push_back(tmp);
                tmp = "";
            }
            else if (s[i] >= 'A')
            {
                tmp += s[i];
            }
            //cout<<sstack.back()<<endl;
        }

        return tmp;
    }
    string repeat(string s, int n)
    {
        string ans;
        for (int i = 0; i < n; i++)
            ans += s;
        return ans;
    }
};