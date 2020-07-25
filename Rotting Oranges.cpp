class Solution {
public:
    int r, c, good = 0, change = 0, step = 0;
    queue<pair<int, int>> q, q1;
    void dfs(vector<vector<int>>& g, int x, int y){
        if(x<0||y<0||x>=r||y>=c)return;
        if(g[x][y] != 1)return;
        q1.push(make_pair(x, y));
        g[x][y] = 2;
        change++;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2)
                    q.push(make_pair(i, j));
                else if(grid[i][j] == 1)
                    good++;
            }
        }
       
        while(!q.empty() && good != 0){
           //cout<<q.size()<<endl;
            while(!q.empty()){
                pair<int, int> s = q.front();
                int x = s.first;
                int y = s.second;
                dfs(grid, x, y + 1);
                dfs(grid, x - 1, y);
                dfs(grid, x, y - 1);
                dfs(grid, x + 1, y);
                q.pop();
            }
            step++;
            if(change == good)break;        
            swap(q, q1);
        }
        return change == good ? step : -1;
    }
};