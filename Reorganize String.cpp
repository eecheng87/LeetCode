class Compare{
public:
    bool operator()(vector<int> a, vector<int>b){
        return a[1] < b[1];
    }
};
class Solution {
public:
    string reorganizeString(string S) {
        vector<int> cnt(26,0);
        string ans;
        ans.resize(S.length());
        int index = 0;
        priority_queue<vector<int>,vector<vector<int>>, Compare> pq;
        for(int i = 0; i < S.length(); i++)
            cnt[S[i]-'a']++;
        for(int i = 0; i < cnt.size(); i++){
            if(cnt[i] > 0)
                pq.push({i,cnt[i]});
        }
        if(2*pq.top()[1] - 1 > S.length())
            return "";
        //cout<<cnt[0]<<endl;
        while(!pq.empty() && index < ans.length()){
            vector<int> tmp = pq.top();
            while(tmp[1] > 0){
                tmp[1]--;
                ans[index] = 'a'+tmp[0];
                index += 2;
                if(index >= ans.length()){
                    index = 1;
                }
            }
            pq.pop();
        }
        return ans;
    }
};