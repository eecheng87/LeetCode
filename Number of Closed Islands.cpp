class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        // fill land touch edge
        int x = 0;
        int y = 0;
        int ans = 0;
        for(int i = 0; i < grid[0].size(); ++i)
            fill_edge(grid,i,0);
        for(int i = 0; i < grid.size(); ++i)
            fill_edge(grid,0,i);
        for(int i = 0; i < grid[0].size(); ++i)
            fill_edge(grid,i,grid.size()-1);
        for(int i = 0; i < grid.size(); ++i)
            fill_edge(grid,grid[0].size()-1,i);
        
        // count answer
        for(int i = 1; i < grid[0].size() - 1; ++i)
            for(int j = 1; j < grid.size() - 1; ++j){
                if(grid[j][i] == 0 && fill_inside(grid,i,j)>0)
                    ans++;
            }
         return ans;
    }
    int fill_inside(vector<vector<int>>& grid,int x, int y){
        //cout<<x<<" "<<y<<endl;
        if(y <= 0 || y >= grid.size()-1 || x <= 0 || x >= grid[0].size()-1 )//|| grid[y][x] == 1)
            return 0;
        if(grid[y][x] == 0){
            grid[y][x] = 1;
            return 1 + fill_inside(grid,x + 1,y) + fill_inside(grid,x - 1,y) + fill_inside(grid,x,y + 1) + fill_inside(grid,x,y - 1);
        }
        return 0;
    }
    void fill_edge(vector<vector<int>>& grid,int x,int y){
        if(x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size())
            return;
        if(grid[y][x] == 1)
            return;
        else{
            grid[y][x] = 1;
            fill_edge(grid,x-1,y);
            fill_edge(grid,x+1,y);
            fill_edge(grid,x,y+1);
            fill_edge(grid,x,y-1);
        }
    }
};