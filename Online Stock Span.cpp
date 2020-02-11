#define val 0
#define cnt 1
class StockSpanner {
public:
    vector<vector<int>> stack;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        if(stack.empty() || stack.back()[val] > price){
            stack.push_back({price,ans});
            return 1;
        }
        while(!stack.empty() && stack.back()[val] <= price){
            ans += stack.back()[cnt];
            stack.pop_back();
        }
        stack.push_back({price,ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */