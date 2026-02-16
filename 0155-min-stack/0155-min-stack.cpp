class MinStack {
    // stack<int>st;
    // int mini;
    stack <pair<int,int>> st;
public:
    MinStack() {
    }
    
    void push(int val) {
        // if(st.empty()){
        //     mini = val;
        //     st.push(val);
        //     return;
        // }
        // if(val > mini){
        //     st.push(val);
        // } else{
        //     st.push(2 * val - mini);
        //     mini = val;
        // }

        if(st.empty()) {
            
            // Push current value as minimum
            st.push( {val, val} );
            return;
        }
        
        // Update the current minimum 
        int mini = min(getMin(), val);
        
        // Add the pair to the stack
        st.push({val, mini});
    }
    
    void pop() {
        // if(st.empty()) return;
        // int x = st.top();
        // st.pop();
        // if(x < mini){
        //     mini = 2*mini - x;
        // }

        st.pop();
    }
    
    int top() {
        // if(st.empty()) return -1;
        // int x = st.top();
        // if(mini < x) return x;

        // return mini;
        return st.top().first;
    }
    
    int getMin() {
        // return mini;
        return st.top().second;
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