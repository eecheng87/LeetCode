class Compare{
public:
    bool operator()(vector<int> a, vector<int> b){
        return a[0]+a[1] > b[0]+b[1];
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>,vector<vector<int>>,Compare> pq;
        if(nums1.empty()||nums2.empty())
            return {};
        vector<vector<int>> ans;
        int x_limit = nums1.size()<k?nums1.size():k;
        int y_limit = nums2.size()<k?nums2.size():k;
        for(int w = 0; w < x_limit; ++w)
            pq.push({nums1[w],nums2[0],w,0});
        //int j = 0;
        //int i = 1;
        /*for(j = 0; j < x_limit; ++j){
            for(i = 1; i < y_limit; ++i){
                if(pq.size() >= k){
                    //cout<<"A"<<endl;
                    vector<int> tmp = pq.top();
                    if(tmp[0]+tmp[1]-nums1[j]-nums2[i] > 0){
                        pq.pop(); 
                        pq.push({nums1[j],nums2[i]});
                    }else{
                        x_limit = j;
                        y_limit = i;
                    }
                                    
                }else{
                    pq.push({nums1[j],nums2[i]});
                }
            }
        }*/
        int i;
        int j;
        int x = 0;
        int y = 1;
        for(i = 0; i < k && !pq.empty(); ++i){
            //pq.push({nums1[x],nums2[y]});
            vector<int> tmp = pq.top();
            ans.push_back({tmp[0],tmp[1]});
            pq.pop();
            if(tmp[3] == nums2.size()-1)continue;
            pq.push({nums1[tmp[2]],nums2[tmp[3]+1],tmp[2],tmp[3]+1});        
        }

        
        return ans;
    }
};