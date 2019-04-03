class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 999999;
        int sell;
        int profit = 0;
        int ans;
        for(int i=0; i<prices.size(); i++){
            if(prices[i]<buy)
                buy = prices[i];
            if(prices[i]-buy > profit){
                ans = i;
                profit = prices[i] - buy;
            }
        }
        
        return profit?profit:0;
    }
};