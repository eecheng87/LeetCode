class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int>ans;
        if(prerequisites.empty()){
            for(int i=0;i<numCourses;i++)
                ans.push_back(i);
            return ans;
        }
        vector<int> in(numCourses,0);
        vector<vector<int>> g = build(numCourses,prerequisites,in);
        vector<int>emp;
        vector<bool>canVisit(numCourses,true);
        deque<int> queue;
        for(int i=0; i<in.size(); i++)
            if(!in[i])
                queue.push_back(i);
    
        while(!queue.empty()){
            int cur = queue.front();
            queue.pop_front();
            ans.push_back(cur);
          
            for(int i=0; i<g[cur].size(); i++){
                in[g[cur][i]]--;
                if(canVisit[g[cur][i]]&&in[g[cur][i]]==0){
                    queue.push_back(g[cur][i]);
                    canVisit[g[cur][i]]=false;
                }
            }
        }
        return ans.size()==numCourses?ans:emp;
    }
    vector<vector<int>> build(int num,vector<pair<int,int>> pre,vector<int>&in){
        vector<vector<int>> g(num,vector<int>(0));
        for(int i=0;i<pre.size();i++){
            in[pre[i].first]++;
            g[pre[i].second].push_back(pre[i].first);
        }
        return g;
    }
};