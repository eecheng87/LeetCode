class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        if(a[1] != b[1])
            return a[1] > b[1];
        else
            return a[0] > b[0];
    }
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> valid;
        vector<int> ans;
        for(int i = 0; i < restaurants.size(); i++){
            if(restaurants[i][2] == 0 && veganFriendly!=0)continue;
            if(restaurants[i][3] > maxPrice)continue;
            if(restaurants[i][4] > maxDistance)continue;
            valid.push_back(restaurants[i]);
        }
        sort(valid.begin(),valid.end(),cmp);
        
        for(int i = 0; i < valid.size(); i++){
            ans.push_back(valid[i][0]);
        }
        
        return ans;
        
    }
};