class Solution {
public:
    int r,c;
    queue<pair<int, int>> q;
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        r = matrix.size();
        c = matrix[0].size();
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 1)
                    ans[i][j] = 1e8;
                else
                    q.push(make_pair(i, j));
            }
        }
        int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        q.push(make_pair(0, 0));
        while(!q.empty()){
            pair<int, int> p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int xx = x + dir[i][0];
                int yy = y + dir[i][1];
                if(xx < 0 || xx >= r || yy < 0 || yy >= c)continue;
                if(ans[x][y] > ans[xx][yy])continue;
                if(ans[xx][yy] == 1e8){
                    
                    q.push(make_pair(xx, yy));
                }
                    ans[xx][yy] = min(ans[xx][yy], ans[x][y] + 1);
                
            }
            
        }
        return ans;
    }
};