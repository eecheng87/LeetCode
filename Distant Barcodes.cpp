class Compare{
  public:
    bool operator()(vector<int> a, vector<int> b){
        return a[1] < b[1];
    }
};
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int index = 0;
        int odd_index = -1;
        vector<int> ans(barcodes.size(),0);
        unordered_map<int,int> mp;
        priority_queue<vector<int>,vector<vector<int>>,Compare>pq;
        
        for(int i = 0; i < barcodes.size(); i++)
            mp[barcodes[i]]++;
        
        for(unordered_map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
            pq.push({it->first,it->second});
        }
        
        while(!pq.empty()){
            vector<int> tmp = pq.top();
            
            while(tmp[1] > 0 && index < ans.size()){
                ans[index] = tmp[0];
                index+=2;
                tmp[1]--;
            } 
            
            if(tmp[1] > 0 && odd_index < 0){
                odd_index = 1;
            }
            
            while(tmp[1] > 0){
                ans[odd_index] = tmp[0];
                odd_index += 2;
                tmp[1]--;
            }
            
            pq.pop();
        }
        
        return ans;
    }
};