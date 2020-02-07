class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        priority_queue<int,vector<int>,less<int>> pq;
        vector<vector<int>> ans(row,vector<int>(col,0));
        for(int i = 0; i < col; i++){
            int x = i;
            int y = 0;
            while(x < col && y < row){
                pq.push(mat[y][x]);
                x++;
                y++;
            }
            x--,y--;
            while(!pq.empty()){
                ans[y][x] = pq.top();
                x--;
                y--;
                pq.pop();
            }
        }
        for(int i = 1; i < row; i++){
            int x = 0;
            int y = i;
            while(x < col && y < row){
                pq.push(mat[y][x]);
                x++;
                y++;
            }
            x--,y--;
            while(!pq.empty()){
                ans[y][x] = pq.top();
                x--;
                y--;
                pq.pop();
            }
        }
        return ans;
    }
};