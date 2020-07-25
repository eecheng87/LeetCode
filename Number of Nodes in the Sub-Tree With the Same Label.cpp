class Solution {
public:
    string labels;
    int* dfs(vector<vector<int>>& g, vector<bool>& vis, vector<int>& ans, int cur){
        vis[cur] = true;
        //vector<int> v(26, 0);
        //vector<int> res(26, 0);
        //int v[26] = {0};
        int res[26] = {0};
        res[labels[cur] - 'a'] = 1;
        for(int i = 0; i < g[cur].size(); i++){
            if(vis[g[cur][i]])
                continue;
            int* v = dfs(g, vis, ans, g[cur][i]);
            for(int j = 0; j < 26; j++){
                res[j] += v[j];
            }
        }
        ans[cur] = res[labels[cur] - 'a'];
        
        return res;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string label) {
        vector<vector<int>> g(n, vector<int>());
        vector<int> ans(n);
        vector<bool> vis(n, false);
        for(int i = 0; i < edges.size(); i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        labels = label;
        dfs(g, vis, ans, 0);
        return ans;
    }
};