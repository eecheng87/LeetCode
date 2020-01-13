class Compare
{
public:
    bool operator() (vector<int>&a, vector<int>&b)
    {
        return a[1]*a[1]+a[0]*a[0] < b[1]*b[1]+b[0]*b[0];
    }
};
class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>>ans;
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        for(int i = 0; i < points.size(); ++i){
            pq.push(points[i]);
            if(pq.size()>K)
                pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
   
};