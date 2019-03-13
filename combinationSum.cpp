class Solution
{
  public:
    vector<vector<int>> ans;
    vector<int> test;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        vector<int> node;

        int sum = 0;
        //for(int i=0;i<candidates.size();i++)
        //candidates.pop_back();
        //candidates.pop_back();
        sort(begin(candidates), end(candidates));
        for (int i = 0; i < candidates.size(); i++)
            solve(candidates, node, candidates[i], target, -1, 0);

        //ans.push_back(test);
        return ans;
    }

    void solve(vector<int> cand, vector<int> node, int sum, int target, int last, int first)
    {

        if (last < 0)
        {
            node.push_back(sum);
        }
        if (sum > target)
            return;
        if (sum < target && last >= 0)
        {
            sum += last;
            node.push_back(last);
        }
        if (sum == target)
        {
            //test.push_back(1);
            ans.push_back(node);
            return;
        }

        for (int i = first; i < cand.size(); i++)
        {
            if (sum > target)
                break;
            if (last < 0 && sum > cand[i])
                continue;
            if (last > cand[i])
                continue;
            solve(cand, node, sum, target, cand[i], i);
        }
    }
};