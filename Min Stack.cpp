class MinStack {
private:
    vector<int> vec;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        vec.push_back(x);
    }
    
    void pop() {
        vec.pop_back();
    }
    
    int top() {
        return vec.back();
    }
    
    int getMin() {
        int min=INT_MAX;
        for(int i=0;i<vec.size();i++)
            min=min>=vec[i]?vec[i]:min;
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */