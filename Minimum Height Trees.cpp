class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> g(n);
        for (int i = 0; i < edges.size(); i++)
        {

            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> q;
        if (n == 1)
        {
            q.push_back(0);
            return q;
        }
        // push leaf into queue
        for (int i = 0; i < g.size(); i++)
        {
            if (g[i].size() == 1)
                q.push_back(i);
        }
        while (1)
        {
            vector<int> next;
            for (int i : q)
            {
                for (int j : g[i])
                {
                    for (int k = 0; k < g[j].size(); k++)
                        if (g[j][k] == i)
                        {
                            g[j].erase(g[j].begin() + k);
                            // break;
                        }
                    if (g[j].size() == 1)
                        next.push_back(j);
                }
            }
            if (next.size() == 0)
                return q;
            q = next;
        }
    }
};