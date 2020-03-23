class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int ans = 0;
        priority_queue<int,vector<int>,less<int>> pq;
        for(int i = 0; i < light.size(); i++){
            pq.push(light[i]);
            if(pq.top() == pq.size())
                ans++;
        }
        return ans;
    }
};