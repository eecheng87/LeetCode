class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        // there are 8 method to wins (3 in rows, cols and diag)
        vector<int>a(8,0);
        vector<int>b(8,0);
        for(int i = 0; i < moves.size(); ++i){
            int row = moves[i][0];
            int col = moves[i][1];
            vector<int> &player = i%2==0?a:b;
            player[row]++;
            player[col+3]++;
            if(row==col)player[6]++;
            if(row+col==2)player[7]++;
        }
        for(int i = 0; i < 8; ++i){
            if(a[i]==3)return "A";
            if(b[i]==3)return "B";
        }
        return moves.size()==9?"Draw":"Pending";
    }
};