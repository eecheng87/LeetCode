class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0)
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m*n-1;
        int index = 0;
        while(left<right){
            index = (left + right-1)/2;
            //cout<<index<<endl;
            if(matrix[index/n][index%n] < target){
                left = index + 1;
            }else{
                right = index;
            }
        }
        
        return (matrix[left/n][left%n] == target);//?true:false;
    }
};