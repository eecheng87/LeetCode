class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans(arr1.size(),0);
        unordered_map<int,int> map;
        int index = 0;
        for(int i = 0; i < arr1.size(); ++i){
            map[arr1[i]]++;
        }
        for(int i = 0; i < arr2.size(); ++i){
            while(map[arr2[i]] > 0){
                ans[index] = arr2[i];
                map[arr2[i]]--;
                index++;
            }
            map.erase(arr2[i]);
        }
        
        // ordering remain key
        // sorting
        std::map<int,int> omap(map.begin(),map.end());
        for(auto it = omap.begin(); it != omap.end(); it++){
            while(it->second > 0){
                ans[index] = it->first;
                it->second--;
                index++;
            }
        }
        return ans;
    }
};