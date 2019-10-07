class Solution {
public:
    vector<int> dir = {0,1,0,-1,0};
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=-100;
        for(int i=0; i<grid.size(); ++i)
            for(int j=0; j<grid[i].size(); ++j)
                if(grid[i][j]!=0)
                    ans = max(ans,grid[i][j]+dfs(grid,i,j));
        return ans;
    }
    int dfs(vector<vector<int>>&grid,int i,int j){
        int tmp = grid[i][j];
        grid[i][j] = 0;
        int ans = 0;
        for(int n=0; n<4; ++n){
            // all direction
            int x = dir[n]+i;
            int y = dir[n+1]+j;
            if(x>=0&&y>=0&&x<grid.size()&&y<grid[i].size()&&grid[x][y]!=0){
            ans = max(ans,grid[x][y]+dfs(grid,x,y));    
            }
        }
        grid[i][j] = tmp;
        return ans;
    }
};