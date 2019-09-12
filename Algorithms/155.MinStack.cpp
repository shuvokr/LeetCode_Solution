class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    int minValue;
    MinStack() {
        minValue = INT_MAX;
    }
    
    void push(int x) {
        st.push(x);
    }
    
    void pop() {
        if(!st.empty()) st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        vector<int> v;
        minValue = INT_MAX;
        while(!st.empty()) {
            minValue = min(minValue, st.top());
            v.push_back(st.top());
            st.pop();
        }
        for(int i = v.size() - 1; i > -1; i--)
            st.push(v[i]);
        return minValue;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
