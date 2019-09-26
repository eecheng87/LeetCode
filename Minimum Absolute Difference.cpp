class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        int min=100000;
        vector<int>tmp;
        for(int i=arr.size()-1; i>0; i--){
            if(min>arr[i]-arr[i-1]){
                ans.clear();
                min = arr[i]-arr[i-1];
                tmp.clear();
                tmp.push_back(arr[i-1]);
                tmp.push_back(arr[i]);
                ans.push_back(tmp);
            }else if(min==arr[i]-arr[i-1]){
                tmp.clear();
                tmp.push_back(arr[i-1]);
                tmp.push_back(arr[i]);     
                ans.insert(ans.begin(),tmp);
            }
        }
        return ans;
    }
};