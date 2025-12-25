class MinStack {
public:
    
    stack<int> st;
    stack<int> min;
    MinStack() {
        
    }
    
    void push(int val) {

       st.push(val);

       if (min.empty())
         min.push(val);
       else
       {
          int minVal = min.top();
          if (val < minVal)
            minVal = val;
          min.push(minVal);
       } 
       
    }
    
    void pop() {
        if (st.empty())
          return;
        
        st.pop();
        min.pop();
    }
    
    int top() {
        if (st.empty())
          return INT_MAX;
        
        return st.top();
    }
    
    int getMin() {
        if (min.empty())
          return INT_MAX;
        
        return min.top();
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