#define Start 0
#define End 1
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a < b;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),cmp);
        
        if(!intervals.empty())ans.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][Start] <= ans.back()[End]){
                // merge
                ans.back()[End] = max(ans.back()[End],intervals[i][End]);
                // cout<<ans.back()[Start]<<" "<<ans.back()[End]<<endl;
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};