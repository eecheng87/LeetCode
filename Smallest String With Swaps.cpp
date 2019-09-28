class Solution
{
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {

        vector<int> v(s.size(), -1);
        vector<vector<int>> m(s.size());

        for (int i = 0; i < pairs.size(); i++)
        {
            int a = find(v, pairs[i][0]);
            int b = find(v, pairs[i][1]);
            if (a != b)
                v[b] = a;
        }
        for (int i = 0; i < v.size(); i++)
            m[find(v, i)].push_back(i);
        for (int i = 0; i < m.size(); i++)
        {
            string ss = "";
            for (int j = 0; j < m[i].size(); j++)
            {
                ss += s[m[i][j]];
            }
            sort(ss.begin(), ss.end());
            for (int j = 0; j < m[i].size(); j++)
            {
                s[m[i][j]] = ss[j];
            }
        }

        return s;
    }
    int find(vector<int> &v, int i)
    {
        if (v[i] < 0)
            return i;
        return v[i] = find(v, v[i]); // return parent index
    }
};