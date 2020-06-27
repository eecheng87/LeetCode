class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int r[m], l[m], h[m];
        for(int i = 0; i < m; i++)l[i] = h[i] = 0;
        for(int i = 0; i < m; i++)r[i] = m;
        int ans = 0; 
        for(int i = 0; i < n; i++){
            int curr = m, curl = 0;
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    h[j]++;
                }else{
                    h[j] = 0;
                }
            }
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    l[j] = max(l[j], curl);
                }else{
                    l[j] = 0;
                    curl = j+1;
                }
            }
            for(int j = m-1; j >= 0; j--){
                if(matrix[i][j] == '1'){
                    r[j] = min(r[j], curr);
                }else{
                    r[j] = m;
                    curr = j;
                }
            }
            for(int j = 0; j < m; j++){
                ans = max(ans, h[j]*(r[j] - l[j]));
            }
        }
        return ans;
    }
};