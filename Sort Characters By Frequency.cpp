class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        priority_queue<int,vector<int>,less<int>> pq;
        vector<string> bucket(s.size()+1,"");
        string ans;
        for(int i = 0; i < s.size(); ++i){
            map[s[i]]++;
        }
        for(unordered_map<char,int>::iterator it = map.begin();it!=map.end();++it){
            int n = it->second;
            char c = it->first;
            bucket[n].append(n,c);
        }
        for(int i = s.size(); i >= 0; --i){
            if(!bucket[i].empty())
                ans.append(bucket[i]);
        }
        return ans;
    }
};