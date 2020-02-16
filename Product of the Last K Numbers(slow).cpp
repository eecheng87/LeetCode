class ProductOfNumbers {
public:
    vector<int> list;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        list.push_back(num);
    }
    
    int getProduct(int k) {
        int ans = 1;
        int n = list.size();
        for(int i = n-1; i > n-1-k; i--)
            ans *= list[i];
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */