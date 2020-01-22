class Compare{
public:
    bool operator()(unordered_map<string,int>:: iterator a,unordered_map<string,int>::iterator b){
        if(a->second == b->second)
            return a->first.compare(b->first) > 0;
        else
            return a->second < b->second;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> map;
        priority_queue<unordered_map<string,int>::iterator,vector<unordered_map<string,int>::iterator>,Compare> pq;
        vector<string>ans;
        for(int i = 0; i < words.size(); ++i)
            map[words[i]]++;
        //for(auto i:map)
          //  cout<<i.second<<endl;
        for(unordered_map<string,int>::iterator it = map.begin(); it!=map.end(); it++){
            pq.push(it);
        }
        
        while(ans.size()!=k){
            ans.push_back(pq.top()->first);
            pq.pop();
        }
        
        return ans;
    }
};