class Solution {
public:
    static bool cmp_func(vector<int>&a, vector<int>&b){
        return a[1]*a[1]+a[0]*a[0] < b[1]*b[1]+b[0]*b[0];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(),points.end(),cmp_func);
        vector<vector<int>> ans(points.begin(),points.begin()+K);
        return ans;
    }
   
};