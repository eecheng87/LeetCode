class Compare{
public:
    bool operator()(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
};
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(events.begin(),events.end());//,cmp);
        //for(auto i:events)
          //  cout<<i[0]<<" "<<i[1]<<endl;
        int index = 0;
        int ans = 0;
        //int i = 1;
        int i;
        for(i = 1; i <= 100000; i++){
        
            if(events.size() == index && pq.empty())
                return ans;
        //while(events.size() > index){
            while(index < events.size() && events[index][0] == i){
                pq.push(events[index][1]);
                index++; 
            }
            while(!pq.empty() && pq.top() < i){
                //cout<<i<<" "<<pq.top()[0]<<endl;
                pq.pop();
            }
            if(!pq.empty()){
                pq.pop();
                ans++;
            }
            //i++;
        }
        cout<<i<<endl;
        return ans;
    }
};