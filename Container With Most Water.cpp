class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        for(int i=0;i<height.size();i++)
            for(int j=i+1;j<height.size();j++){
                ans=max(ans,min(height[i],height[j])*(j-i));
            }
        return ans;
    }
    int max(int a,int b){
        return a>b?a:b;
    }
    int min(int a,int b){
        return a>b?b:a;
    }
};