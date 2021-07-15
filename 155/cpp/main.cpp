class MinStack {
public:
    
    stack<pair<int, int>> s;
    
    /** initialize your data structure here. */
    MinStack() {
    
    }
    
    void push(int val) {
        int m = s.empty() ? val : min(val, s.top().second);
        s.push(make_pair(val, m));
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
