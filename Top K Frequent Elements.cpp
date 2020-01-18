class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
            map[nums[i]]++;
        }
        
        for (std::unordered_map<int,int>::iterator it=map.begin(); it!=map.end(); ++it){
            pq.push(it->second);
        }
        
        // pop priority size less than K
        while(pq.size() != k){
            cout<<pq.top()<<endl;
            pq.pop();
        }
        
        for (std::unordered_map<int,int>::iterator it=map.begin(); it!=map.end(); ++it){
            if(it->second >= pq.top()){
                ans.push_back(it->first);
            }
        }
        
        return ans;
    }
};