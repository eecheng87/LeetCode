class ProductOfNumbers {
public:
    vector<int> list = {1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0){
            //list.clear();
            list = {1};
        }else{
            list.push_back(list.back() * num);
        }
    }
    
    int getProduct(int k) {
        return k >= list.size()? 0: list.back()/list[list.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */