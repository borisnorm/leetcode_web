class MinStack {
    Stack<Integer> st;
    Stack<Integer> min;

    public MinStack() {
        st = new Stack<Integer>();
        min = new Stack<Integer>();
    }
    
    public void push(int val) {

        st.push(val);

        if (min.isEmpty())
          min.push(val);
        else
        {
           int minVal = min.peek();
           if (val < minVal)
             minVal = val;
           min.push(minVal);
        }    
    }
    
    public void pop() {
        if (st.isEmpty())
          return;
        
        st.pop();
        min.pop();
    }
    
    public int top() {
        if (st.isEmpty())
          return Integer.MAX_VALUE;
        
        return st.peek();
    }
    
    public int getMin() {
        if (min.isEmpty())
          return Integer.MAX_VALUE;
        
        return min.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */