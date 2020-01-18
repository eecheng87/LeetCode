class Compare{
public:
    bool operator()(vector<int>a, vector<int>b){
        return a[2] > b[2];
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>,vector<vector<int>>,Compare>pq;
        vector<int> tp;
        for(int i = 0; i < matrix.size(); i++){
            pq.push({i,0,matrix[i][0]});
        }
        // {col,row,value}
        
        while(k > 0){
            k--;
            tp = pq.top();
            pq.pop();
            if(tp[1] == matrix.size()-1)continue;
            pq.push({tp[0],tp[1]+1,matrix[tp[0]][tp[1]+1]});
        }
        return tp[2];
    }
};