class Solution
{
  public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> ans;

        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> tmp(i + 1, 1);
            ans.push_back(tmp);
        }
        //int i;
        for (int i = 2; i <= rowIndex; i++)
            for (int j = 1; j < i; j++)
            {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }

        vector<int> row;

        for (int j = 0; j <= rowIndex; j++)
            row.push_back(ans[rowIndex][j]);

        return row;
    }
};