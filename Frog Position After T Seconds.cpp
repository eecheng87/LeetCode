class Solution {
public:
    double ans = 0;
    int ta;
    int time;
    void find(double p,vector<int>& v,vector<vector<int>>& edges,int node,int t){
        
        if(node == ta && t == time){
            ans = p;
            return;
        }
        if(t > time){
            //ans = 0;
            return;
        }
        bool flag = true;
        for(int i = 0; i < edges.size(); i++){
            if(edges[i][0] == node){
                find(p/v[edges[i][0]-1],v,edges,edges[i][1],t+1);
                flag = false;
            }
        }
        if(flag)
            find(p,v,edges,node,t+1);
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        ta = target;
        time = t;
        vector<int> v(n,0);
        for(int i = 0; i < edges.size(); i++){
            if(edges[i][0] > edges[i][1]){
                int tmp = edges[i][1];
                edges[i][1] = edges[i][0];
                edges[i][0] = tmp;
            }
        }
        for(int i = 0; i < edges.size(); i++){
            v[edges[i][0]-1]++;
        }
        //cout<<edges[0][0]<<" "<<edges[0][1]<<endl;
        //cout<<edges[1][0]<<" "<<edges[1][1]<<endl;
        find(1,v,edges,1,0);
        return ans;
    }
};