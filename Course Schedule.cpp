class Solution
{
  private:
    vector<vector<int>> g;

  public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<int> eachSize(numCourses, 0);
        g = geneGraph(numCourses, prerequisites, eachSize);
        vector<bool> canVist(numCourses, true);
        int j;

        for (int i = 0; i < numCourses; i++)
        {
            for (j = 0; j < numCourses; j++)
            {
                if (eachSize[j] == 0 && canVist[j])
                {
                    canVist[j] = false;
                    break;
                }
            }
            if (j >= numCourses)
                break;
            for (int i = 0; i < numCourses; i++)
            {
                for (int k = 0; k < g[i].size(); k++)
                {
                    if (g[i][k] == j)
                    {
                        g[i].erase(g[i].begin() + k);
                        eachSize[i]--;
                    }
                }
            }
        }
        return allVisted(canVist) ? true : false;
    }
    vector<vector<int>> geneGraph(int num, vector<pair<int, int>> p, vector<int> &e)
    {
        vector<vector<int>> g(num, vector<int>(0));
        for (int i = 0; i < p.size(); i++)
        {
            g[p[i].second].push_back(p[i].first);
            e[p[i].second]++;
        }
        return g;
    }
    bool allVisted(vector<bool> v)
    {
        // return whether there still node doesn't delete
        for (int i = 0; i < v.size(); i++)
            if (v[i])
                return false;
        return true;
    }
};