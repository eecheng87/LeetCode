class Solution {
public:
    int ans = 0;
    void find(vector<int>& man, vector<int>& info,int node,int time){
        if(man[node] < 0){
            ans = max(ans,time);
            return;
        }
        time += info[man[node]];
        find(man,info,man[node],time);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for(int i = 0; i < informTime.size(); i++){
            if(informTime[i] == 0){
                find(manager,informTime,i,0);
            }
        }
        return ans;
    }
};