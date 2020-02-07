class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> rank;
        vector<int> cpy(arr.begin(),arr.end());
        vector<int> ans(arr.size(),0);
        sort(cpy.begin(),cpy.end());
        int cur = 1;
        if(!arr.empty())rank[cpy.front()] = cur;
        for(int i = 1; i < cpy.size(); ++i){
            if(rank[cpy[i-1]] != rank[cpy[i]]){
                rank[cpy[i]] = ++cur;
            }
        }
        for(int i = 0; i < ans.size(); ++i){
            ans[i] = rank[arr[i]];
        }
        return ans;
    }
};