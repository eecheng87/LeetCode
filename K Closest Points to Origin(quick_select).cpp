class Solution {
public:
    int cmp(vector<int>a,vector<int>b){
        return a[1]*a[1]+a[0]*a[0]-b[1]*b[1]-b[0]*b[0];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int len = points.size();
        int l = 0;
        int r = len-1;
        while(l <= r){
            int mid = help(points,l,r);
            if(mid == K){
                break;
            }
            if(mid < K){
                l = mid + 1; 
            }else{
                r = mid - 1;
            }
        }
        vector<vector<int>> ans(points.begin(),points.begin()+K);
        return ans;
    }
    int help(vector<vector<int>>&points,int l,int r){
        // return mid value
        vector<int> pivot = points[l];
        while(l < r){
            while (l < r && cmp(points[r], pivot) >= 0) r--;
            points[l] = points[r];
            while (l < r && cmp(points[l], pivot) <= 0) l++;
            points[r] = points[l];
        }
        points[l] = pivot;
        return l;
    }
};