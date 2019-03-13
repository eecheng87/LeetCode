
class Solution
{
  public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        int length = nums.size();

        permute(nums, 0, length - 1);

        return ans;
    }
    void swap(vector<int> &node, int a, int b)
    {

        int tmp;
        tmp = node[a];
        node[a] = node[b];
        node[b] = tmp;
    }

    void permute(vector<int> str, int start, int end)
    {

        if (start == end)
        {
            if (!check(str))
                ans.push_back(str);
        }
        else
        {

            for (int i = start; i <= end; i++)
            {

                swap(str, start, i);
                permute(str, start + 1, end);
                swap(str, start, i);
            }
        }
    }

    bool check(vector<int> str)
    {

        int same = 0;
        if (ans.empty())
            return false;

        vector<int> tmp;

        for (int i = 0; i < ans.size(); i++)
        {

            tmp = ans[i];

            if (same == tmp.size())
                return true; //duplicate
            else
                same = 0;

            for (int j = 0; j < tmp.size(); j++)
            {
                if (tmp[j] == str[j])
                    same++;
            }
        }

        if (same == tmp.size())
            return true;
        else
            return false;
    }
};