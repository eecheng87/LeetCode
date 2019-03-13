class Solution
{
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> m;
        unordered_map<int, int>::const_iterator got;
        vector<int> ans;
        vector<int> shor;
        vector<int> lon;
        if (nums1.size() < nums2.size())
        {
            shor = nums1;
            lon = nums2;
        }
        else
        {
            shor = nums2;
            lon = nums1;
        }

        for (int i = 0; i < shor.size(); i++)
        {
            got = m.find(shor[i]);

            if (got == m.end())
            {
                m[shor[i]] = 1;
            }
            else
            {
                m[shor[i]]++;
            }
        }

        for (int i = 0; i < lon.size(); i++)
        {
            if (m.find(lon[i]) == m.end() || m[lon[i]] < 1)
            {
            }
            else
            {
                ans.insert(ans.begin(), lon[i]);
                m[lon[i]]--;
            }
        }
        return ans;
    }
};