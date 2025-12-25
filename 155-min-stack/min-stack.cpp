class MinStack {
public:

    stack<int> min;
    stack<int> st;

    MinStack() {
        
    }
    
    void push(int val) {
        
        st.push(val);

        stack<int> st_tmp;
        while(!min.empty() && val > min.top())
        {
           int st_val = min.top();
           st_tmp.push(st_val);
           min.pop();
        }

        min.push(val);

        while (!st_tmp.empty())
        {
           int st_val = st_tmp.top();
           min.push(st_val);
           st_tmp.pop();
        }
       
        
    }
    
    void pop() {
        if (st.empty())
          return;
        
        stack<int> st_tmp;
        int val = st.top();
        st.pop();
        
        while(!min.empty() && min.top() != val)
        {
           int st_val = min.top();
           st_tmp.push(st_val);
           min.pop();
        }

        min.pop();

        while(!st_tmp.empty())
        {
            int st_val = st_tmp.top();
            min.push(st_val);
            st_tmp.pop();
        }

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