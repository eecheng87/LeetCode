class Solution
{
  public:
    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int> &nums)
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
};